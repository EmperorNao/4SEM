#include "NonLinearEquationSolver.h"


std::pair<bool, double> solve_nonlinear_equation(RationalFunction f, double left, \
	double right, double eps, int max_step) {

	double x0_x, x0_k;
	if (autograd_1dim(f, left) * autograd_2ndderiv_1dim(f, left) >= 0) {

		x0_x = right;
		x0_k = left;

	}
	else {

		x0_x = left;
		x0_k = right;

	}

	double x1_k = x0_k - f(x0_k) / autograd_1dim(f, x0_k);
	double t = x1_k;

	double x1_x = x0_x - (f(x0_x) * (t - x0_x)) / (f(t) - f(x0_x));
	x0_x = x1_k;
	x0_k = x1_k;

	int step = 0;
	while ((abs(x1_k - x1_x) > eps) and (step < MAX_STEP)) {


		x1_k = x0_k - f(x0_x) / autograd_1dim(f, x0_k);
		t = x1_k;

		x1_x = x0_k - (f(x0_x) * (t - x0_x)) / (f(t) - f(x0_k));
		step++;
		x0_x = x1_k;
		x0_k = x1_k;

	}

	return { step < MAX_STEP, (x1_x + x1_k) / 2 };

}