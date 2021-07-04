#include "Eigenvalue.h"


std::vector<double> normalyze_vector(std::vector<double> v) {

	auto new_v = v;
	double sum = 0;
	for (int i = 0; i < v.size(); ++i) {

		sum += v[i];

	}
	sum = sqrt(sum);
	for (int i = 0; i < v.size(); ++i) {

		new_v[i] /= sum;

	}
	return new_v;


}


std::vector<double> operator-(std::vector<double> a, std::vector<double> b) {

	std::vector<double> new_v = a;
	if (a.size() == b.size()) {

		for (int i = 0; i < a.size(); ++i) {

			new_v[i] = a[i] - b[i];

		}

		return new_v;

	}
	else {

		std::cout << "Bad dimension\n";
		abort();

	}

}


std::vector<double> operator/(std::vector<double> v, double b) {
	
	std::vector<double> new_v = v;
	for (int i = 0; i < v.size(); ++i) {

		new_v[i] /= b;

	}
	return new_v;

}


double operator*(std::vector<double> a, std::vector<double> b) {

	if (a.size() == b.size()) {

		double sum = 0;
		for (int i = 0; i < a.size(); ++i) {

			sum += a[i] * b[i];

		}

		return sum;

	}
	else {

		std::cout << "Bad dimension\n";
		abort();

	}

}


std::pair<double, std::vector<double>> max_eigenvalue_eigenvector(Matr& matr, \
	double eps) {

	auto size = matr.size();
	int m = size.first;
	int n = size.second;

	std::vector<double> x_0(m, 1);
	x_0 = normalyze_vector(x_0);

	auto y = matr * x_0;
	double lambda = x_0 * y;
	auto x_1 = y / vector_norm(y, 2);
	double last_lambda;
	std::vector<double> distance;

	do {

		last_lambda = lambda;
		x_0 = x_1;

		y = matr * x_0;
		lambda = x_0 * y;
		x_1 = y / vector_norm(y, 2);
		last_lambda;

	}
	while ((abs(last_lambda - lambda) > eps) or (vector_norm(x_1 - x_0, 2) > eps));

	return { lambda, x_1 };

}
