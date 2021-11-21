#include "Integral.h"


double integrate_by_central_rectangles(RationalFunction func, double a, double b, int n, double eps) {

	double last_value = 0;

	if (n < 0) {

		n = 8;

	}
	double h = (b - a) / n;
	double sum = 0;
	for (int i = 0; i < n; ++i) {

		sum += func(a + h*(0.5 + i));

	}

	do {

		last_value = h * sum;
		n *= 2;
		h = (b - a) / n;
		sum = 0;
		for (int i = 0; i < n; ++i) {

			sum += func(a + h * (0.5 + i));

		}
	
	} while (abs(h * sum - last_value) / 3 > eps);

	return last_value;

}


double integrate_by_trapezoids(RationalFunction func, double a, double b, int n, double eps) {

	double last_value = 0;

	if (n < 0) {

		n = 8;

	}
	double h = (b - a) / n;
	double sum = (func(b) + func(a)) / 2;
	for (int i = 1; i < n; ++i) {

		sum += func(a + h * i);

	}

	do {

		last_value = h * sum;
		n *= 2;
		h = (b - a) / n;
		sum = (func(b) + func(a)) / 2;
		for (int i = 1; i < n; ++i) {

			sum += func(a + h * i);

		}

	} while (abs(h * sum - last_value) / 3 > eps);
	return last_value;

}


double integrate_by_parabols(RationalFunction func, double a, double b, int n, double eps) {

	double last_value = 0;

	if (n < 0) {

		n = 8;

	}
	double h = (b - a) / n;
	double sum_even = 0;
	double sum_odd = 0;
	for (int i = 1; i < n; ++i) {

		if (i % 2 == 0) {

			sum_even += func(a + h * (i));

		}
		else {

			sum_odd += func(a + h * (i));

		}

	}

	do {
		
		last_value = h * (4 * sum_odd + 2 * sum_even + func(a) + func(b)) / 3;
		n *= 2;
		h = (b - a) / n;
		sum_even = 0;
		sum_odd = 0;
		for (int i = 1; i < n; ++i) {

			if (i % 2 == 0) {

				sum_even += func(a + h * (i));

			}
			else {

				sum_odd += func(a + h * (i));

			}

		}

	} while (abs(h * (4 * sum_odd + 2 * sum_even + func(a) + func(b)) / 3 - last_value)/15 > eps);
	return last_value;

}


double integrate_by_gauss(RationalFunction func, double a, double b, int n) {

	// Значения в узлах
	// так как статик, то инициализация происходит только при первом вызове
	A(0, 0) = 2;	A(0, 1) = 1;	A(0, 2) = 0.5555556;	A(0, 3) = 0.3478548;
	A(1, 0) = 0;	A(1, 1) = 1;	A(1, 2) = 0.8888888;	A(1, 3) = 0.6521451;
	A(2, 0) = 0;	A(2, 1) = 0;	A(2, 2) = 0.5555556;	A(2, 3) = 0.6521451;
	A(3, 0) = 0;	A(3, 1) = 0;	A(3, 2) = 0;			A(3, 3) = 0.3478548;

	t(0, 0) = 0;	t(0, 1) = -0.5773502;	t(0, 2) = -0.7745967;	t(0, 3) = -0.8611363;
	t(1, 0) = 0;	t(1, 1) =  0.5773502;	t(1, 2) = 0;			t(1, 3) = -0.3399810;
	t(2, 0) = 0;	t(2, 1) = 0;			t(2, 2) = 0.7745967;	t(2, 3) = 0.3399810;
	t(3, 0) = 0;	t(3, 1) = 0;			t(3, 2) = 0;			t(3, 3) = 0.8611363;

	if ((n < 0) or (n > 4)) {

		n = 4;

	}
	double sum = 0;
	for (int i = 0; i < n; ++i) {

		sum += A(i, n - 1) * func((b + a)/2 + (b - a) * t(i, n - 1)/2);

	}
	return (b - a) * sum / 2;

};
