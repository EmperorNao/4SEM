#include "Iteration.h"


double vector_norm(std::vector<double> arr, int norm) {

	if (norm <= 0) {

		double max = abs(arr[0]);

		for (int i = 1; i < arr.size(); ++i) {

			if (abs(arr[i]) > max) {

				max = abs(arr[i]);

			}

		}
		return max;

	}
	else {

		double value = 0;
		for (int i = 0; i < arr.size(); ++i) {

			value += abs(pow(arr[i], norm));

		}

		double degree = 1.0 / norm;
		value = pow(value, degree);
		return value;

	}

}


double matr_norm(Matr& matr, int norm) {

	auto size = matr.size();
	int m = size.first;
	int n = size.second;

	std::vector<double> v_norm;
	if (norm == -1) {

		v_norm.resize(n);
		for (int j = 0; j < n; ++j) {

			v_norm[j] = 0;
			for (int i = 0; i < m; ++i) {

				v_norm[j] += abs(matr(i, j));

			}

		}

	}
	else if (norm == 1) {

		v_norm.resize(m);
		for (int i = 0; i < m; ++i) {

			v_norm[i] = 0;
			for (int j = 0; j < n; ++j) {

				v_norm[i] += abs(matr(i, j));

			}

		}

	}

	return vector_norm(v_norm, -1);

}


std::vector<double> solve_linear_system(Matr& matr, double eps) {

	auto size = matr.size();
	int m = size.first;
	int n = size.second;

	std::vector<double> last_start(m);
	for (int i = 0; i < m; ++i) {

		matr.mult_i_row_by_k(i, 1/matr(i, i));
		last_start[i] = matr(i, n - 1);

	}

	Matr B(m, n - 1);
	for (int i = 0; i < m; ++i) {

		for (int j = 0; j < n - 1; ++j) {

			if (i == j) {

				B(i, j) = 0;

			}
			else {

				B(i, j) = -matr(i, j);

			}

		}

	}

	std::cout << "B = \n" << B << std::endl;
	std::cout << "c = \n";
	for (int i = 0; i < last_start.size(); ++i) {

		std::cout << last_start[i] << " ";

	}
	std::cout << std::endl << std::endl;
	double inf_norm = matr_norm(B, -1);
	double first_norm = matr_norm(B, 1);
	
	double used_norm = inf_norm < first_norm ? inf_norm : first_norm;

	double new_eps = (1 - used_norm) / used_norm * eps;

	auto start = last_start;
	for (int i = 0; i < m; ++i) {

		start[i] = 0;
		for (int j = 0; j < n - 1; ++j) {

			start[i] += last_start[j] * B(i, j);

		}
		start[i] += matr(i, n - 1);

	}


	auto difference = start;
	for (int i = 0; i < start.size(); ++i) {

		difference[i] = start[i] - last_start[i];

	}
	std::cout << "x_0 = \n" ;
	for (int i = 0; i < last_start.size(); ++i) {

		std::cout << last_start[i] << " ";

	}
	std::cout << std::endl;
	std::cout << "x_1 = \n"  ;
	for (int i = 0; i < start.size(); ++i) {

		std::cout << start[i] << " ";

	}
	std::cout << std::endl;
	std::cout << "x_1 - x_0 = \n"  ;
	for (int i = 0; i < difference.size(); ++i) {

		std::cout << difference[i] << " ";

	}
	std::cout << std::endl;
	std::cout << std::endl;

	while (vector_norm(difference, -1) > new_eps) {

		last_start = start;
		for (int i = 0; i < m; ++i) {

			start[i] = 0;
			for (int j = 0; j < n - 1; ++j) {

				start[i] += last_start[j] * B(i, j);

			}
			start[i] += matr(i, n - 1);

		}

		difference = start;
		for (int i = 0; i < start.size(); ++i) {

			difference[i] = start[i] - last_start[i];

		}
		std::cout << "x_0 = \n"  ;
		for (int i = 0; i < last_start.size(); ++i) {

			std::cout << last_start[i] << " ";

		}
		std::cout << std::endl;
		std::cout << "x_1 = \n" ;
		for (int i = 0; i < start.size(); ++i) {

			std::cout << start[i] << " ";

		}
		std::cout << std::endl;
		std::cout << "x_1 - x_0 = \n" ;
		for (int i = 0; i < difference.size(); ++i) {

			std::cout << difference[i] << " ";

		}
		std::cout << std::endl;
		std::cout << std::endl;

	}

	auto etta = start * matr;
	for (int i = 0; i < etta.size(); ++i) {

		std::cout << "etta_" << i + 1 << " = " << abs(matr(i, n - 1) - etta[i]) << std::endl;

	}

	return start;

}