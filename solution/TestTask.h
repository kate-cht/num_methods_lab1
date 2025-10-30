#pragma once
#include"TrueSolution.h"
#include<list>
#include<vector>
#include<algorithm>
#include <utility>
#include <string>
class TestTask
{
private:
	std::vector<std::pair<double, double>> Distance_Ui_Vi;
protected:
	int iter{};
	struct Parametrs {
		//границы
		double a{};
		double b{};
		//шаг интегрирования
		double h{};
		//нач условия
		double U0{};
		//левая окрестность выхода на границу
		double E_border{};
		//контроль лок погрешности
		double E_error{};
		//максимальное число допустимого числа итераций
		int Nmax{};
	};
	Parametrs parametrs;
	std::list<double> Errors_List; //хранит все ОЛП на каждом шаге
	std::list<std::pair<double, double>> step_xn;
	virtual double f(const double& x, const double& U);	
	double To_Find_k1(const double& x, const double& V);
	double To_FInd_k2(const double& x, const double& V, const double& h, double const& k1);
	double To_Find_k3(const double& x, const double& V, const double& h, double const& k2);
	double To_Find_k4(const double& x, const double& V, const double& h, double const& k3);
	void To_find_Max_Distance_Ui_Vi();
	void To_Find_max_OLP();
	void To_Find_max_step();
	void To_Find_min_step();
	
public:
	std::list<std::vector<double>> TABLE_INFORMATION; //вот здесь все строки таблицы
	std::vector<std::string> TABLE_NAME;
	TestTask(const double& A, const double& B, const double& H, const double& u, const double& E_b, const double& E_e, const int& n);
	~TestTask();

	void Make_Step_RK_4(double& x, double& V, const double& h);
	virtual void Solve_Without_Control();
	virtual int Control_Error(double& X, double& V, double& X2, double& V2, double& x_old, double& v_old, double& S, double& count_doubling, double& count_reduction);
	virtual void Solve_With_Control(); //ПРОВЕРЬ ЧТО ВСЕ ВИРТУАЛЬНЫЕ
	struct Info {
		int n{};
		double B_xn{};
		double MaxOLP{};
		int DoublingCount{};
		int ReductionCount{};
		std::pair<double, double> max_hi_xi{};
		std::pair<double, double> min_hi_xi{};
		std::pair<double, double> maxU_V{};
		bool Is_inf{ false };
	};
	Info final_info;
	Info get_info();
	std::list<std::vector<double>> get_table();
};

