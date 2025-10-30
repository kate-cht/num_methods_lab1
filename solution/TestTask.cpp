#include "TestTask.h"
#include "TrueSolution.h"


TestTask::TestTask(const double& A, const double& B, const double& H, const double& u, const double& E_b, const double& E_e, const int& n) {
	parametrs.a = A;
	parametrs.b = B;
	parametrs.h = H;
	parametrs.U0 = u;
	parametrs.E_border = E_b;
	parametrs.E_error = E_e;
	parametrs.Nmax = n;
}

TestTask::~TestTask() {
	parametrs.a = 0.0;
	parametrs.b = 0.0;
	parametrs.h = 0.0;
	parametrs.U0 = 0.0;
	parametrs.E_border = 0.0;
	parametrs.E_error = 0.0;
	parametrs.Nmax = 0;
}

void TestTask::To_find_Max_Distance_Ui_Vi() {
	if (Distance_Ui_Vi.empty()) {
		final_info.maxU_V = std::make_pair(0.0, 0.0);
	}

	auto max_it = std::max_element(Distance_Ui_Vi.begin(), Distance_Ui_Vi.end(),
		[](const std::pair<double, double>& a, const std::pair<double, double>& b) {
			return a.second < b.second;
		});
	final_info.maxU_V = std::make_pair(max_it->first, max_it->second);
}
void TestTask::To_Find_max_OLP() {
	final_info.MaxOLP = *std::max_element(Errors_List.begin(), Errors_List.end());
}

void TestTask::To_Find_max_step() {
	final_info.max_hi_xi = *std::max_element(step_xn.begin(), step_xn.end(),
		[](const std::pair<double, double>& a, const std::pair<double, double>& b) {
			return a.first < b.first;
		});
}
void TestTask::To_Find_min_step() {
	final_info.min_hi_xi = *std::min_element(step_xn.begin(), step_xn.end(),
		[](const std::pair<double, double>& a, const std::pair<double, double>& b) {
			return a.first < b.first;
		});
}
double TestTask::f(const double& x, const double& U) {
	return U;
}

double TestTask::To_Find_k1(const double& x, const double& V) {
	return f(x, V);
}

double TestTask::To_FInd_k2(const double& x, const double& V, const double& h, double const& k1) {
	return f(x + h / 2.0, V + (h / 2.0) * k1);
}
double TestTask::To_Find_k3(const double& x, const double& V, const double& h, double const& k2) {
	return f(x + h / 2.0, V + (h / 2.0) * k2);
}
double TestTask::To_Find_k4(const double& x, const double& V, const double& h, double const& k3) {
	return f(x + h, V + h * k3);
}
void TestTask::Make_Step_RK_4(double& x, double& V, const double& h) {
	double K1 = To_Find_k1(x, V);
	double K2 = To_FInd_k2(x, V, h, K1);
	double K3 = To_Find_k3(x, V, h, K2);
	double K4 = To_Find_k4(x, V, h, K3);
	x += h;
	V = V + (h / 6.0) * (K1 + 2 * K2 + 2 * K3 + K4);
}

void TestTask::Solve_Without_Control() {
	TABLE_INFORMATION.clear();
	Distance_Ui_Vi.clear();
	step_xn.clear();
	Errors_List.clear();
	final_info = Info{};

	double X = parametrs.a;
	double U = To_Find_True_Solution(X, parametrs.U0);
	double V = To_Find_True_Solution(X, parametrs.U0);

	std::vector<double> Table_Row_0 = { 0.0, X, V, parametrs.h, U, std::abs(U - V) };
	TABLE_INFORMATION.emplace_back(Table_Row_0);
	TABLE_NAME = { "i", "x_i", "v_i", "h", "u_i", "|u_i - v_i|" };

	double x_old = X;
	double u_old = U;
	double v_old = V;

	bool Flag_Exit = false;
	for (int i = 1; i <= parametrs.Nmax; i++) {

		Make_Step_RK_4(X, V, parametrs.h);
		U = To_Find_True_Solution(X, parametrs.U0);

		if (X > parametrs.E_border + parametrs.b) {
			X = x_old;
			U = u_old;
			V = v_old;
			parametrs.h = parametrs.b - x_old;

			Make_Step_RK_4(X, V, parametrs.h);
			U = To_Find_True_Solution(X, parametrs.U0);

			Flag_Exit = true;
		}
		if (X >= parametrs.b - parametrs.E_border && X <= parametrs.b) {
			Flag_Exit = true;
		}
		Distance_Ui_Vi.emplace_back(std::make_pair(X, std::abs(U - V)));
		std::vector<double> Table_Row_i = { static_cast<double>(i), X, V, parametrs.h, U, std::abs(U - V) };
		TABLE_INFORMATION.emplace_back(Table_Row_i);
		++final_info.n;
		if (Flag_Exit) {
			break;
		}
		else {
			x_old = X;
			u_old = U;
			v_old = V;
		}
		To_find_Max_Distance_Ui_Vi();
	}
}
int TestTask::Control_Error(double& X, double& V, double& X_EXTRA, double& V_EXTRA, double& OLD_X, double& OLD_V, double& S, double& CURRENT_DOUBLING, double& CURRENT_REDUCTION)
{
	if (abs(S) < parametrs.E_error / pow(2, 5)) {
		parametrs.h *= 2;
		++final_info.DoublingCount;
		++CURRENT_DOUBLING;

		return 0;
	}
	else if (abs(S) > parametrs.E_error) {
		bool FLAG_TO_EXIT = false;
		double h = parametrs.h;
		while (!FLAG_TO_EXIT) {

			h /= 2;
			++CURRENT_REDUCTION;
			++final_info.ReductionCount;

			V = OLD_V;
			X = OLD_X;
			V_EXTRA = V;
			X_EXTRA = X;

			for (int i = 0; i < 2; ++i) {
				Make_Step_RK_4(X_EXTRA, V_EXTRA, h / 2.0);
			}
			Make_Step_RK_4(X, V, h);

			S = (V_EXTRA - V) / (pow(2, 4) - 1);
			if (abs(S) <= parametrs.E_error) {
				FLAG_TO_EXIT = true;
				parametrs.h = h;
			}
		}

		return 1;
	}
}

void TestTask::Solve_With_Control() {
	// Очистка контейнеров
	TABLE_INFORMATION.clear();
	Distance_Ui_Vi.clear();
	step_xn.clear();
	Errors_List.clear();
	final_info = Info{};

	double X = parametrs.a;
	double U = To_Find_True_Solution(X, parametrs.U0);
	double V = To_Find_True_Solution(X, parametrs.U0);
	std::vector<double> Table_Row_0 = { 0.0, X, V, V, 0.0, 0.0, parametrs.h, 0.0, 0.0, U, std::abs(U - V)};
	TABLE_INFORMATION.emplace_back(Table_Row_0);
	TABLE_NAME = { "i", "x_i", "v_i", "v2_i", "v_i - v2_i", "OЛП", "h", "C1", "C2", "ui", "|ui-vi|"};

	double x_old = X;
	double u_old = U;
	double v_old = V;


	for (int i = 1; i <= parametrs.Nmax; ++i) {
		double curr_doubling{};//h*2
		double curr_reduction{};//h:2

		double V2 = V;
		double X2 = X;
		//алгоритм стр 12
		Make_Step_RK_4(X, V, parametrs.h);
		Make_Step_RK_4(X2, V2, parametrs.h / 2.0);
		Make_Step_RK_4(X2, V2, parametrs.h / 2.0);

		double S = (V2 - V) / (pow(2.0, 4) - 1.0);
		Errors_List.emplace_back(S * pow(2.0, 4));
		double H = parametrs.h;
		int step_control = Control_Error(X, V, X2, V2, x_old, v_old, S, curr_doubling, curr_reduction);

		double step;
		if (step_control == 0) {
			step = H;
		}
		else {
			step = parametrs.h;
		}
		U = To_Find_True_Solution(X, parametrs.U0);

		if (X < parametrs.b - parametrs.E_border) {
			std::vector<double> Table_Row_i = { static_cast<double>(i), X, V, V2, V - V2, S * pow(2.0,4), parametrs.h, curr_reduction, curr_doubling, U, std::abs(U - V) };
			TABLE_INFORMATION.emplace_back(Table_Row_i);
			++final_info.n;
			step_xn.emplace_back(std::make_pair(parametrs.h, X));
		}
		bool Flag_Exit = false;
		if (X >= parametrs.b - parametrs.E_border && X <= parametrs.b) {

			std::vector<double> Table_Row_i = { static_cast<double>(i), X, V, V2, V - V2, S * pow(2.0,4), parametrs.h, curr_reduction, curr_doubling, U, std::abs(U - V) };
			TABLE_INFORMATION.emplace_back(Table_Row_i);

			Distance_Ui_Vi.emplace_back(X, std::abs(U - V));
			++final_info.n;
			step_xn.emplace_back(std::make_pair(parametrs.h, X));
			Flag_Exit = true;
		}
		if (X > parametrs.b) {
			X = x_old;
			U = u_old;
			V = v_old;

			parametrs.h = parametrs.b - X;
			Make_Step_RK_4(X, V, parametrs.h);

			U = To_Find_True_Solution(X, parametrs.U0);
			Distance_Ui_Vi.emplace_back(X, std::abs(U - V));

			std::vector<double> Table_Row_ = { static_cast<double>(i), X, V, V2, V - V2, S * pow(2.0,4), parametrs.h, curr_reduction, curr_doubling, U, std::abs(U - V) };
			TABLE_INFORMATION.emplace_back(Table_Row_);
			++final_info.n;
			Flag_Exit = true;
		}
		if (Flag_Exit) {
			break;
		}
		else {
			Distance_Ui_Vi.emplace_back(X, std::abs(U - V));
			x_old = X;
			u_old = U;
			v_old = V;
		}
	}

	final_info.B_xn = parametrs.b - X;

	To_Find_max_OLP();
	To_Find_max_step();
	To_Find_min_step();
	To_find_Max_Distance_Ui_Vi();
}

TestTask::Info TestTask::get_info() {
	return final_info;
}
std::list<std::vector<double>> TestTask::get_table() {
	return TABLE_INFORMATION;
}