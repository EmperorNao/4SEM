#include "CrushingGradientDescent.h"
#include <fstream>


std::pair<bool, std::vector<double>> crushing_gradient_descent(RealFunction& func, \
	crushing_config config) {

	std::random_device rd{};
	std::mt19937 gen{ rd() };

	// values near the mean are the most likely
	// standard deviation affects the dispersion of generated values from the mean
	std::normal_distribution<> d;

	int number_dimensions = config.number_of_variables;
	std::vector<double> start(number_dimensions);

	std::ofstream out(config.filename);

	if (number_dimensions != 0) {

		for (int i = 0; i < number_dimensions; i++) {

			start[i] = d(gen);

		}

	}
	else {

		start = config.points;
		if (start.size() < 1) {

			return std::make_pair(false, std::vector<double>(0));

		}

	}

	std::vector<double> estimate = start;
	int number_of_steps = 0;

	double alpha = config.lr;
	double beta = config.beta;
	double gamma = config.gamma;
	double eps = config.eps;
	bool logs = config.logs;

	double functional = func(start);

	while (number_of_steps < config.MAX_STEPS) {

		auto gradient = autograd(func, estimate);
		if ((logs) and (number_of_steps % config.number_steps_to_log == 0)) {

			out << "Parameteres values: " << std::endl;

		}
		
		std::vector<double> new_x;
		double gamma_degree = -1;
		double grad_square = 0;
		double v = 0;
		for (int i = 0; i < gradient.size(); ++i) {

			grad_square += gradient[i] * gradient[i];

		}
		if (grad_square < eps * eps) {

			if ((logs) and (number_of_steps % config.number_steps_to_log == 0)) {

				for (int i = 0; i < estimate.size(); ++i) {

					out << "x_" << i << " = " << estimate[i] << std::endl;

				}
				if ((logs) and (number_of_steps % config.number_steps_to_log == 0)) {

					auto current_functional = func(estimate);
					out << "Last function value = " << functional << ". Current value = " << current_functional << ". Delta = " \
						<< functional - current_functional << std::endl;

				}

			}
			return std::make_pair(true, estimate);

		}
		do {

			new_x = estimate;
			gamma_degree++;
			v = pow(gamma, gamma_degree);
			for (int i = 0; i < new_x.size(); ++i) {

				new_x[i] = estimate[i] - alpha * v * gradient[i];

			}

			double p = func(new_x) - func(estimate);

		} while (func(new_x) - func(estimate) >= -beta * alpha * v * grad_square);

		v = pow(gamma, gamma_degree);
		for (int i = 0; i < new_x.size(); ++i) {

			estimate[i] = estimate[i] - alpha * v * gradient[i];
			if ((logs) and (number_of_steps % config.number_steps_to_log == 0)) {

				out << "x_" << i << " = " << estimate[i] << std::endl;

			}

		}

		auto current_functional = func(estimate);
		if ((logs) and (number_of_steps % config.number_steps_to_log == 0)) {

			out << "Last function value = " << functional << ". Current value = " << current_functional << ". Delta = " \
				<< functional - current_functional << std::endl;

		}

		if (abs(functional - current_functional) < eps) {

			break;

		}
		functional = current_functional;
		number_of_steps++;

	}

	return std::make_pair(number_of_steps < config.MAX_STEPS, estimate);

}