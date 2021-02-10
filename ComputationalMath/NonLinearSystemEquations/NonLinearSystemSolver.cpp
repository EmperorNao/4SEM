#include "NonLinearSystemSolver.h"


std::pair<bool, std::vector<double>> solve_nonlinear_system(std::vector<RationalFunction> system, std::vector<double> start, \
	 double eps, int max_iteration) {

	int current_iteration = 0;
	double sum_of_abs = INT_MAX;
	RealMatr matr(system.size(), system.size() + 1);
	std::vector<double> solution = start;

	while ((current_iteration < max_iteration) and (sum_of_abs > eps)) {

		++current_iteration;
		sum_of_abs = 0;
		
		for (int i = 0; i < system.size(); ++i) {

			std::vector<double> gradient = autograd(system[i], solution);
			for (int j = 0; j < system.size(); ++j) {

				matr(i, j) = gradient[j];

			}
			matr(i, system.size()) = -system[i](solution);

		}

		forward_pass(matr);
		std::vector<double> delta = back_propagation(matr);

		for (int i = 0; i < solution.size(); ++i) {

			solution[i] += delta[i];

		}

		for (int i = 0; i < system.size(); ++i) {

			sum_of_abs += abs(system[i](solution));

		}

	}

	return { current_iteration < max_iteration, solution };

}