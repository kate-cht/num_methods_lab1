#pragma once
#include"TestTask.h"
class FirstTask : public TestTask
{
protected:
	virtual double f(const double& X, const double& U) override;
public:
	FirstTask(const double& A, const double& B, const double& H, const double& u0, const double& E_b, const double& E_e, const int& n)
		: TestTask(A, B, H, u0, E_b, E_e, n) {};
	void Solve_Without_Control() override;
	void Solve_With_Control() override;
};

