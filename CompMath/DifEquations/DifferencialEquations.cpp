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