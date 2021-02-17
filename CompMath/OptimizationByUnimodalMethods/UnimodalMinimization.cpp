#include "UnimodalMinimization.h"


double unimodal_optimal_search_minimization(RationalFunction func, \
	double left, double right, double eps) {

	int N = int((right - left) / eps - 1);
	double step = 1 / ((double)N + 1);

	double min_x = left;
	double min_y = func(left);

	double current_x, current_y;

	for (int i = 1; i < N; ++i) {

		current_x = left + i * step;
		current_y = func(current_x);
		if (current_y < min_y) {

			min_x = current_x;
			min_y = current_y;

		}

	}
	return min_x;

}


double half_division_optimal_search_minimization(RationalFunction func, \
	double left, double right, double eps) {

	double delta = eps / 10;
	double a = left;
	double b = right;

	double alpha, beta;
	while (abs(b - a) > eps) {

		alpha = (a + b) / 2 - delta;
		beta = (a + b) / 2 + delta;
		if (func(alpha) > func(beta)) {

			a = alpha;

		}
		else {

			b = beta;

		}

	}
	
	return (a + b) / 2;

}


double fibonacci_optimal_search_minimization(RationalFunction func, \
	double left, double right, double eps) {

	std::vector<int> fibonacci_number(FIBONACCI_N + 1);
	fibonacci_number[0] = 1;
	fibonacci_number[1] = 1;
	for (int i = 2; i < FIBONACCI_N + 1; ++i) {

		fibonacci_number[i] = fibonacci_number[i - 1] + fibonacci_number[i - 2];

	}

	double a = left;
	double b = right;

	double alpha, beta;

	for (int i = 0; i < FIBONACCI_N - 1; ++i) {

		alpha = a + double(fibonacci_number[FIBONACCI_N - 1 - i - 1]) / fibonacci_number[FIBONACCI_N - 1 - i + 1] * (b - a);
		beta = a + double(fibonacci_number[FIBONACCI_N - 1 - i]) / fibonacci_number[FIBONACCI_N - 1 - i + 1] * (b - a);

		if (func(alpha) > func(beta)) {

			a = alpha;

		}
		else {

			b = beta;

		}

	}
	return func(alpha) > func(beta) ? beta : alpha;


}