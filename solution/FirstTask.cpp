#include "FirstTask.h"
#include <iomanip>
double FirstTask::f(const double& X, const double& U)
{
	return  (X / (1 + X * X)) * pow(U, 2.0) + U - pow(U, 3.0) * sin(10.0 * X);
}


void FirstTask::Solve_With_Control()
{
	TABLE_INFORMATION.clear();
	step_xn.clear();
	Errors_List.clear();
	final_info = Info{};
	double X = parametrs.a;
	double V = parametrs.U0;

	std::vector<double> TABLE_ROW1 = { 0.0, X, V, V, 0.0, 0.0, parametrs.h, 0.0, 0.0 };
	TABLE_INFORMATION.emplace_back(TABLE_ROW1);
	TABLE_NAME = { "i", "x_i", "v_i", "v2_i", "v_i - v2_i", "OËÏ", "h", "C1", "C2" };
	double OLD_X = X;
	double OLD_V = V;

	for (int i = 1; i <= parametrs.Nmax; ++i)
	{
		double CURRENT_DOUBLING{};
		double CURRENT_REDUCTION{};

		double V_EXTRA = V;
		double X_EXTRA = X;


		for (int j = 0; j < 2; ++j) {
			Make_Step_RK_4(X_EXTRA, V_EXTRA, parametrs.h / 2.0);
		}
		Make_Step_RK_4(X, V, parametrs.h);

		if (std::isinf(V) || std::isnan(V) || std::isinf(V_EXTRA) || std::isnan(V_EXTRA)) {
			final_info.Is_inf = true;
			break;
		}

		double S = (V_EXTRA - V) / (pow(2.0, 4) - 1.0);
		Errors_List.emplace_back(abs(S * pow(2.0, 4)));
		double H = parametrs.h;
		int step_control = Control_Error(X, V, X_EXTRA, V_EXTRA, OLD_X, OLD_V, S, CURRENT_DOUBLING, CURRENT_REDUCTION);
		double step;
		if (step_control == 0) {
			step = H;
		}
		else {
			step = parametrs.h;
		}
		double LP = abs(S * pow(2.0, 4));

		if (X < parametrs.b - parametrs.E_border) {
			std::vector<double> TABLE_ROW = { static_cast<double>(i), X, V, V_EXTRA, V - V_EXTRA, LP, parametrs.h, CURRENT_REDUCTION, CURRENT_DOUBLING };
			TABLE_INFORMATION.emplace_back(TABLE_ROW);

			++final_info.n;
			step_xn.emplace_back(std::make_pair(parametrs.h, X));
		}

		bool EXIT_FROM_FOR = false;
		if (X >= parametrs.b - parametrs.E_border && X <= parametrs.b) {
			std::vector<double> TABLE_ROW = { static_cast<double>(i), X, V, V_EXTRA, V - V_EXTRA, LP, parametrs.h, CURRENT_REDUCTION, CURRENT_DOUBLING };
			TABLE_INFORMATION.emplace_back(TABLE_ROW);

			++final_info.n;
			step_xn.emplace_back(std::make_pair(parametrs.h, X));

			EXIT_FROM_FOR = true;
		}

		if (X > parametrs.b) {
			X = OLD_X;
			V = OLD_V;

			parametrs.h = parametrs.b - OLD_X;
			Make_Step_RK_4(X, V, parametrs.h);

			std::vector<double> TABLE_ROW = { static_cast<double>(i), X, V, V_EXTRA, V - V_EXTRA, LP, parametrs.h, CURRENT_REDUCTION, CURRENT_DOUBLING };
			TABLE_INFORMATION.emplace_back(TABLE_ROW);
			++final_info.n;

			EXIT_FROM_FOR = true;
		}

		if (EXIT_FROM_FOR) {
			break;
		}
		else {
			OLD_X = X;
			OLD_V = V;
		}


	}

	final_info.B_xn = parametrs.b - X;
	To_Find_max_step();
	To_Find_min_step();
	To_Find_max_OLP();
}

void FirstTask::Solve_Without_Control() {
	TABLE_INFORMATION.clear();
	step_xn.clear();
	Errors_List.clear();
	final_info = Info{};
	double X = parametrs.a;
	double V = parametrs.U0;

	std::vector<double> TABLE_ROW1 = { 0.0, X, V, parametrs.h };
	TABLE_INFORMATION.emplace_back(TABLE_ROW1);
	TABLE_NAME = { "i", "x_i", "v_i", "h"};

	double OLD_X = X;
	double OLD_V = V;

	bool FLAG_TO_EXIT = false;
	for (int i = 1; i <= parametrs.Nmax; ++i)
	{
		Make_Step_RK_4(X, V, parametrs.h);

		if (std::isinf(V) || std::isnan(V)) {
			final_info.Is_inf = true;
			break;
		}

		if (X > parametrs.b) {
			X = OLD_X;
			V = OLD_V;

			parametrs.h = parametrs.b - OLD_X;
			Make_Step_RK_4(X, V, parametrs.h);
			FLAG_TO_EXIT = true;
		}

		std::vector<double> TABLE_ROW = { static_cast<double>(i), X, V, parametrs.h };
		TABLE_INFORMATION.emplace_back(TABLE_ROW);
		++final_info.n;

		if (FLAG_TO_EXIT)
			break;
		else {
			OLD_X = X;
			OLD_V = V;
		}
	}
}

