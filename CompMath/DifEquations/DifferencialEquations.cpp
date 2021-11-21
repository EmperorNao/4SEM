#include "DifferencialEquations.h"
#include <functional>


solution solve_by_euler_method(RealFunction func, double x_0, \
	double y_0, double x, double eps) {

	int n = number_of_steps;
	double last_value = y_0;
	double error;

	double step = (x - x_0) / n;
	for (int i = 1; i < n; ++i) {

		last_value += step * func({ x_0 + i * step, last_value });


	}

	double last_counted_value;
	do {

		n *= 2;
		step = (x - x_0) / n;
		last_counted_value = last_value;
		last_value = y_0;

		for (int i = 1; i < n; ++i) {

			last_value += step * func({ x_0 + i * step, last_value });


		}

		error = abs(last_counted_value - last_value);
	} while ((error > eps) and (n < MAX_STEP));

	return { last_counted_value, error };

}


solution solve_by_euler_cauchy_method(RealFunction func, double x_0, \
	double y_0, double x, double eps) {

	int n = number_of_steps;
	double last_value = y_0;
	double error;

	double step = (x - x_0) / n;
	for (int i = 1; i < n; ++i) {

		double t = func({ x_0 + (i - 1) * step, last_value });
		last_value += 0.5 * step * (t + func({ x_0 + (i - 1) * step,\
			last_value + step * t }));


	}

	double last_counted_value;
	do {

		n *= 2;
		step = (x - x_0) / n;
		last_counted_value = last_value;
		last_value = y_0;

		for (int i = 1; i < n; ++i) {

			double t = func({ x_0 + (i - 1) * step, last_value });
			last_value += 0.5 * step * (t + func({ x_0 + (i - 1) * step,\
				last_value + step * t }));


		}

		error = abs(last_counted_value - last_value) / 3;
	} while ((error > eps) and (n < MAX_STEP));

	return { last_counted_value, error };

}


solution solve_by_modified_euler_method(RealFunction func, double x_0, \
	double y_0, double x, double eps) {

	int n = number_of_steps;
	double last_value = y_0;
	double error;

	double step = (x - x_0) / n;
	for (int i = 1; i < n; ++i) {

		last_value += step * func({ x_0 + (i - 1) * step + step / 2,\
			last_value + step / 2 * func({x_0 + (i - 1) * step, last_value}) });


	}

	std::cout << last_value << std::endl;
	double last_counted_value;
	do {

		n *= 2;
		step = (x - x_0) / n;
		last_counted_value = last_value;
		last_value = y_0;

		for (int i = 1; i < n; ++i) {

			double t = func({ x_0 + (i - 1) * step, last_value });
			last_value += step * func({ x_0 + (i - 1) * step + step / 2,\
				last_value + step / 2 * func({x_0 + (i - 1) * step, last_value}) });


		}

		error = abs(last_counted_value - last_value) / 3;
	} while ((error > eps) and (n < MAX_STEP));

	return { last_counted_value, error };

}


solution solve_by_runge_kutta_method(RealFunction func, double x_0, \
	double y_0, double x, double eps) {

	int n = number_of_steps;
	double last_value = y_0;
	double error;

	double step = (x - x_0) / n;
	double m_1, m_2, m_3, m_4;
	for (int i = 1; i < n; ++i) {

		m_1 = func({ x_0 + (i - 1) * step, last_value });
		m_2 = func({ x_0 + (i - 1) * step + step / 2, last_value + step * m_1 / 2 });
		m_3 = func({ x_0 + (i - 1) * step + step / 2, last_value + step * m_2 / 2 });
		m_4 = func({ x_0 + (i - 1) * step + step, last_value + step * m_3});

		last_value += step * (m_1 + 2*m_2 + 2*m_3 + m_4) / 6;

	}

	double last_counted_value;
	do {

		n *= 2;
		step = (x - x_0) / n;
		last_counted_value = last_value;
		last_value = y_0;

		for (int i = 1; i < n; ++i) {

			m_1 = func({ x_0 + (i - 1) * step, last_value });
			m_2 = func({ x_0 + (i - 1) * step + step / 2, last_value + step * m_1 / 2 });
			m_3 = func({ x_0 + (i - 1) * step + step / 2, last_value + step * m_2 / 2 });
			m_4 = func({ x_0 + (i - 1) * step + step, last_value + step * m_3 });

			last_value += step * (m_1 + 2*m_2 + 2*m_3 + m_4) / 6;

		}

		error = abs(last_counted_value - last_value) / 15;
	} while ((error > eps) and (n * 3 < MAX_STEP));

	return { last_counted_value, error };


}


void write_to_stream_values(RealFunction func, std::ostream& os, double x_0, \
	double y_0, double a, double b, double step, SOLUTION_OF_DIF_EQ sol, \
	double eps) {

	std::function<solution(RealFunction, double, double, double, double)> dif;
	switch (sol) {

	case EULER:
		dif = solve_by_euler_method;
		break;

	case EULER_CAUCHY:
		dif = solve_by_euler_cauchy_method;
		break;

	case MODIFIED_EULER:
		dif = solve_by_modified_euler_method;
		break;

	case RUNGE_KUTTA:
		dif = solve_by_runge_kutta_method;
		break;

	default:
		dif = solve_by_runge_kutta_method;
		break;

	};

	int n = (b - a) / step;
	os << "x		y\n";
	for (int i = 0; i <= n; ++i) {

		double current_x = a + i * step;
		solution s = dif(func, x_0, y_0, current_x, eps);
		os << current_x << "\t\t" << s.value << std::endl;

	}

}


std::vector<double> operator-(std::vector<double> left, std::vector<double> right) {

	std::vector<double> res(left.size());
	for (int i = 0; i < res.size(); ++i) {

		res[i] = left[i] - right[i];

	}
	return res;

}


std::vector<double> operator/(std::vector<double> left, double right) {

	std::vector<double> res(left.size());
	for (int i = 0; i < res.size(); ++i) {

		res[i] = left[i]/right;

	}
	return res;

}


std::vector<double> operator*(std::vector<double> left, std::vector<double> right) {

	std::vector<double> res(left.size());
	for (int i = 0; i < res.size(); ++i) {

		res[i] = left[i] * right[i];

	}
	return res;

}


std::vector<double> operator*(double left, std::vector<double> right) {

	std::vector<double> res(right.size());
	for (int i = 0; i < res.size(); ++i) {

		res[i] = left * right[i];

	}
	return res;

}


std::vector<double> operator+(std::vector<double> left, std::vector<double> right) {

	std::vector<double> res(left.size());
	for (int i = 0; i < res.size(); ++i) {

		res[i] = left[i] + right[i];

	}
	return res;

}


void operator+=(std::vector<double>& left, std::vector<double> right) {

	for (int i = 0; i < left.size(); ++i) {

		left[i] += right[i];

	}
	return;

}


std::vector<double> abs(std::vector<double> left) {

	std::vector<double> res(left.size());
	for (int i = 0; i < res.size(); ++i) {

		res[i] = abs(left[i]);

	}
	return res;

}


double sum(std::vector<double> left) {

	double sum = 0;
	for (int i = 0; i < left.size(); ++i) {

		sum += left[i];

	}
	return sum;

}


std::vector<double> append(std::vector<double> left, std::vector<double> right) {

	std::vector<double> result;
	for (int i = 0; i < left.size(); ++i) {

		result.push_back(left[i]);

	}
	for (int i = 0; i < right.size(); ++i) {

		result.push_back(right[i]);

	}
	return result;

}


std::vector<solution> solve_system_by_runge_kutta_method(std::vector<RealFunction> functions, std::vector<double> x_0, \
	std::vector<double> y_0, std::vector<double> x, double eps, std::function<void(std::vector<double>)> callback) {


		int n = number_of_steps;
		std::vector<double> last_value = y_0;
		std::vector<double> error;

		std::vector<double> step = (x - x_0) / n;
		std::vector<double> m_1, m_2, m_3, m_4;


		for (int i = 1; i < n; ++i) {

			for (int j = 0; j < functions.size(); ++j) {

				m_1.push_back(functions[j](append(x_0 + (i - 1) * step, last_value)));

			}

			for (int j = 0; j < functions.size(); ++j) {

				m_2.push_back(functions[j](append(x_0 + (i - 1) * step + step / 2, last_value + step * m_1 / 2)));

			}

			for (int j = 0; j < functions.size(); ++j) {

				m_3.push_back(functions[j](append(x_0 + (i - 1) * step + step / 2, last_value + step * m_2 / 2)));

			}

			for (int j = 0; j < functions.size(); ++j) {

				m_4.push_back(functions[j](append(x_0 + (i - 1) * step + step, last_value + step * m_3)));

			}

			last_value += step * (m_1 + 2 * m_2 + 2 * m_3 + m_4) / 6;
			if (callback != nullptr) {

				callback(append(x, last_value));

			}

		}

		std::vector<double> last_counted_value;
		do {

			n *= 2;
			step = (x - x_0) / n;
			last_counted_value = last_value;
			last_value = y_0;

			for (int i = 1; i < n; ++i) {

				m_1.resize(0);
				m_2.resize(0);
				m_3.resize(0);
				m_4.resize(0);
				for (int j = 0; j < functions.size(); ++j) {

					m_1.push_back(functions[j](append(x_0 + (i - 1) * step, last_value)));

				}

				for (int j = 0; j < functions.size(); ++j) {

					m_2.push_back(functions[j](append(x_0 + (i - 1) * step + step / 2, last_value + step * m_1 / 2)));

				}

				for (int j = 0; j < functions.size(); ++j) {

					m_3.push_back(functions[j](append(x_0 + (i - 1) * step + step / 2, last_value + step * m_2 / 2)));

				}

				for (int j = 0; j < functions.size(); ++j) {

					m_4.push_back(functions[j](append(x_0 + (i - 1) * step + step, last_value + step * m_3)));

				}

				last_value += step * (m_1 + 2 * m_2 + 2 * m_3 + m_4) / 6;
				if (callback != nullptr) {

					callback(append(x, last_value));

				}

			}

			error = abs(last_counted_value - last_value) / 15;
		} while ((sum(error) > eps) and (n * 3 < MAX_STEP));


		std::vector<solution> sol(functions.size());
		for (int i = 0; i < sol.size(); ++i) {

			sol[i].error = error[i];
			sol[i].value = last_counted_value[i];

		}
		return sol;

}