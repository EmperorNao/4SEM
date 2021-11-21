#include "NonLinearSystemSolver.h"


std::pair<bool, std::vector<double>> solve_nonlinear_system(std::vector<RationalFunction> system, std::vector<double> start,\
	double eps, int max_iteration, std::function<void(std::vector<double>)> callback) {

	int current_iteration = 0;
	double sum_of_abs = INT_MAX*10e10;
	RealMatr matr(system.size(), system.size() + 1);
	std::vector<double> solution = start;

	while ((current_iteration < max_iteration) and (sum_of_abs > eps)) {

		++current_iteration;
		sum_of_abs = 0;
		if (callback != nullptr) {

			callback(solution);

		}
		for (int i = 0; i < system.size(); ++i) {

			std::vector<double> gradient;
			if (system[i].is_cpp_func()) {

				gradient = autograd(system[i].get_function(), solution);

			}
			else {

				gradient = autograd(system[i], solution);

			}
			for (int j = 0; j < system.size(); ++j) {

				matr(i, j) = gradient[j];

			}
			if (!system[i].is_cpp_func()) {

				matr(i, system.size()) = -system[i](solution);

			}
			else {

				matr(i, system.size()) =- system[i].get_function()(solution);

			}

		}

		forward_pass(matr);
		std::vector<double> delta = back_propagation(matr);

		for (int i = 0; i < solution.size(); ++i) {

			solution[i] += delta[i];

		}

		for (int i = 0; i < system.size(); ++i) {

			if (!system[i].is_cpp_func()) {

				sum_of_abs += abs(system[i](solution));

			}
			else {

				sum_of_abs += abs(system[i].get_function()(solution));

			}

		}

	}
	return { current_iteration < max_iteration, solution };

}