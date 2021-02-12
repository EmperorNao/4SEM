#include "Difference.h"
#include <iomanip>


double calculate_poly_with_n_knots_in_x(std::vector<double> points, std::vector<double> values, double x, bool fin) {

	Matrix<double> matr(points.size(), points.size());
	
	for (int i = 0; i < points.size(); ++i) {

		matr(i, 0) = values[i];

	}

	std::cout << "Таблица разностей" << std::endl;
	count_table(matr, points, fin);

	std::cout << std::setprecision(8) << matr;
	double result = 0;
	if (fin) {

		double t = (x - points[0])/(points[1] - points[0]);
		if (abs((round(t) - t)) < 10e-7) {

			t = round(t);

		}

		int denom = 2;
		double mult = t;
		result += matr(0, 0);
		for (int i = 1; i < points.size(); ++i) {

			mult *= t - i;
			double fktp = matr(0, i);
			result += fktp * mult / denom;

			denom *= (i + 2);

		}

	}
	else {

		double mult = 1;
		result += matr(0, 0);
		for (int i = 1; i < points.size(); ++i) {

			mult *= x - points[i - 1];
			result += matr(0, i) * mult;

		}

	}

	return result;

}


bool is_values_evenly(std::vector<double> v) {

	double dist = v[1] - v[0];
	for (int i = 1; i < v.size(); ++i) {

		if (v[i] - v[i - 1] != dist) {

			return 0;

		}

	}
	return 1;


}


void calculate_k_fin_diff_at_n_upside(Matrix<double>& matr, std::vector<double> points, int k, int n, bool fin) {

	matr(n, k) = matr(n + 1, k - 1) - matr(n, k - 1);
	if (not fin) {

		double t = matr(n, k);
		double f = (points[n + k] - points[n]);
		matr(n, k) = t / f;

	}

}


void count_table(Matrix<double>& matr, std::vector<double> points, bool fin) {

	int m = matr.size().first;

	for (int k = 1; k < m; ++k) {

		for (int n = 0; n < m - k; ++n) {

			calculate_k_fin_diff_at_n_upside(matr, points, k, n, fin);

		}

	}

}