#pragma once
#include "TestTask.h"
#include <vector>

class SecondTask :public TestTask
{

protected:

    std::vector<double> f(const double& X, const std::vector<double>& V);
    std::vector<double> find_K1(const double& X, const std::vector<double>& V);
    std::vector<double> find_K2(const double& X, const std::vector<double>& V, const double& h, const std::vector<double>& K1);
    std::vector<double> find_K3(const double& X, const std::vector<double>& V, const double& h, const std::vector<double>& K2);
    std::vector<double> find_K4(const double& X, const std::vector<double>& V, const double& h, const std::vector<double>& K3);
    void Make_Step_RK_4(double& X, std::vector<double>& V, const double& h);

    void Control_Error(double& X, std::vector<double>& V, double& X2, std::vector<double>& V2, double& x_old, std::vector<double>& v_old, double& S, double& count_doubling, double& count_reduction);
    double alpha{};
    double beta{};
    double U0_prime{};
public:

    void set_a_b(double _alpha, double _beta);

    SecondTask(const double& A, const double& B, const double& H,
        const double& u0, const double& u0_prime,
        const double& E_b, const double& E_e, const int& n, const double& alp, const double& bet)
        : TestTask(A, B, H, u0, E_b, E_e, n), U0_prime(u0_prime), alpha(alp), beta(bet) {};

    void Solve_Without_Control() override;
    void Solve_With_Control() override;
};


