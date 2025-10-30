#include "SecondTask.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>

bool is_infin(const std::vector<double>& V, const std::vector<double>& V_EX) {
	bool flag{ false };
	if (std::isinf(V[0]) || std::isnan(V[0])) flag = true;
	if (std::isinf(V[1]) || std::isnan(V[1])) flag = true;
	if (std::isinf(V_EX[0]) || std::isnan(V_EX[0])) flag = true;
	if (std::isinf(V_EX[1]) || std::isnan(V_EX[1])) flag = true;

	return flag;
}
std::vector<double> SecondTask::f(const double& X, const std::vector<double>& V)
{
	double f_1 = V[1];
	double f_2 = -alpha * V[1] - beta * sin(V[0]);

	return { f_1, f_2 };
}

std::vector<double> SecondTask::find_K1(const double& X, const std::vector<double>& V)
{
	return f(X, V);
}

std::vector<double> SecondTask::find_K2(const double& X, const std::vector<double>& V, const double& h, const std::vector<double>& K1)
{
	std::vector<double> new_V{ V[0] + (h / 2.0) * K1[0], V[1] + (h / 2.0) * K1[1] };
	return f(X + h / 2.0, new_V);
}

std::vector<double> SecondTask::find_K3(const double& X, const std::vector<double>& V, const double& h, const std::vector<double>& K2)
{
	std::vector<double> new_V{ V[0] + (h / 2.0) * K2[0], V[1] + (h / 2.0) * K2[1] };
	return f(X + h / 2.0, new_V);
}

std::vector<double> SecondTask::find_K4(const double& X, const std::vector<double>& V, const double& h, const std::vector<double>& K3)
{
	std::vector<double> new_V{ V[0] + h * K3[0], V[1] + h * K3[1] };
	return f(X + h, new_V);
}

void SecondTask::Make_Step_RK_4(double& X, std::vector<double>& V, const double& STEP)
{
	std::vector<double> K1 = find_K1(X, V);
	std::vector<double> K2 = find_K2(X, V, STEP, K1);
	std::vector<double> K3 = find_K3(X, V, STEP, K2);
	std::vector<double> K4 = find_K4(X, V, STEP, K3);

	X += STEP;
	V[0] += (STEP / 6.0) * (K1[0] + 2.0 * K2[0] + 2.0 * K3[0] + K4[0]);
	V[1] += (STEP / 6.0) * (K1[1] + 2.0 * K2[1] + 2.0 * K3[1] + K4[1]);
}

void SecondTask::Control_Error(double& X, std::vector<double>& V, double& X2, std::vector<double>& V2, double& x_old, std::vector<double>& v_old, double& S, double& count_doubling, double& count_reduction)
{
	if (abs(S) < parametrs.E_error / pow(2.0, 5)) {
		parametrs.h *= 2.0;
		++final_info.DoublingCount;
		++count_doubling;
	}
	else if (abs(S) > parametrs.E_error) {
		bool FLAG_TO_EXIT = false;
		double h = parametrs.h;
		while (!FLAG_TO_EXIT) {

			h /= 2.0;
			++count_reduction;
			++final_info.n;

			V = v_old;
			X = x_old;
			V2 = V;
			X2 = X;

			for (int i = 0; i < 2; ++i) {
				Make_Step_RK_4(X2, V2, h / 2.0);
			}
			Make_Step_RK_4(X, V, h);

			double s_1 = (V2[0] - V[0]) / (pow(2.0, 4.0) - 1.0);
			double s_2 = (V2[1] - V[1]) / (pow(2.0, 4.0) - 1.0);
			S = sqrt(s_1 * s_1 + s_2 * s_2);
			if (abs(S) <= parametrs.E_error) {
				FLAG_TO_EXIT = true;
				parametrs.h = h;
			}
		}
	}
}


void SecondTask::Solve_Without_Control()
{
	double X = parametrs.a;
	std::vector<double> V = { parametrs.U0, U0_prime };

	std::vector<double> TABLE_ROW1 = { 0.0, X, V[0],V[1], parametrs.h };
	TABLE_INFORMATION.emplace_back(TABLE_ROW1);
	TABLE_NAME = { "i", "x_i", "v_i", "v'_i", "h" };
	double OLD_X = X;
	std::vector<double> OLD_V = V;

	bool FLAG_TO_EXIT = false;
	for (int i = 1; i <= parametrs.Nmax; ++i)
	{
		Make_Step_RK_4(X, V, parametrs.h);

		std::vector<double> tmp{ 1.0,1.0 };
		if (is_infin(V, tmp)) {
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

		std::vector<double> TABLE_ROW = { static_cast<double>(i), X, V[0],V[1], parametrs.h };
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

void SecondTask::Solve_With_Control()
{
	double X = parametrs.a;
	std::vector<double> V = { parametrs.U0, U0_prime };

	std::vector<double> TABLE_ROW1 = { 0.0, X, V[0], V[1], V[0], V[1], 0.0, 0.0, 0.0, parametrs.h, 0.0, 0.0 };
	TABLE_INFORMATION.emplace_back(TABLE_ROW1);
	TABLE_NAME = { "i", "x_i", "v_i", "v'_i", "v2_i","v'2_i", "v_i - v2_i", "v'_i - v2'_i", "OËÏ", "h", "C1", "C2" };
	double OLD_X = X;
	std::vector<double> OLD_V = V;

	for (int i = 1; i <= parametrs.Nmax; ++i)
	{
		double CURRENT_DOUBLING{};
		double CURRENT_REDUCTION{};

		std::vector<double> V_EXTRA = V;
		double X_EXTRA = X;

		for (int j = 0; j < 2; ++j) {
			Make_Step_RK_4(X_EXTRA, V_EXTRA, parametrs.h / 2.0);
		}
		Make_Step_RK_4(X, V, parametrs.h);

		if (is_infin(V, V_EXTRA)) {
			final_info.Is_inf = true;
			break;
		}

		double s_1 = (V_EXTRA[0] - V[0]) / (pow(2.0, 4.0) - 1.0);
		double s_2 = (V_EXTRA[1] - V[1]) / (pow(2.0, 4.0) - 1.0);
		double S = sqrt(s_1 * s_1 + s_2 * s_2);
		Errors_List.emplace_back(abs(S * pow(2.0, 4.0)));


		Control_Error(X, V, X_EXTRA, V_EXTRA, OLD_X, OLD_V, S, CURRENT_DOUBLING, CURRENT_REDUCTION);
		double LP = abs(S * pow(2.0, 4));

		if (X < parametrs.b - parametrs.E_border) {
			std::vector<double> TABLE_ROW = { static_cast<double>(i), X, V[0],V[1], V_EXTRA[0],V_EXTRA[1], V[0] - V_EXTRA[0],V[1] - V_EXTRA[1], S, parametrs.h, CURRENT_REDUCTION, CURRENT_DOUBLING };
			TABLE_INFORMATION.emplace_back(TABLE_ROW);

			++final_info.n;
			step_xn.emplace_back(std::make_pair(parametrs.h, X));
		}

		bool EXIT_FROM_FOR = false;
		if (X >= parametrs.b - parametrs.E_border && X <= parametrs.b) {
			std::vector<double> TABLE_ROW = { static_cast<double>(i), X, V[0],V[1], V_EXTRA[0],V_EXTRA[1], V[0] - V_EXTRA[0],V[1] - V_EXTRA[1], LP, parametrs.h, CURRENT_REDUCTION, CURRENT_DOUBLING };
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

			std::vector<double> TABLE_ROW = { static_cast<double>(i), X, V[0],V[1], V_EXTRA[0],V_EXTRA[1], V[0] - V_EXTRA[0],V[1] - V_EXTRA[1], LP, parametrs.h, CURRENT_REDUCTION, CURRENT_DOUBLING };
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




