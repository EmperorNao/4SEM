#include "GaussBasisSolution.h"


int row_for_absmax_in_j_column_from_i_row(Matr matr, int _j, int _i) {

	auto sizes = matr.size();
	int m = sizes.first;
	int n = sizes.second;
	Fraction max = matr(_i, _j);
	int index_max = _i;

	if ((0 <= _j < n) and (0 <= _i < m)) {


		for (int i = 1; i < m; ++i) {

			if (max < abs(matr(i, _j))) {

				max = abs(matr(i, _j));
				index_max = i;

			}

		}

	}

	return index_max;

}


int forward_pass(Matr& matr) {

	auto sizes = matr.size();
	int m = sizes.first;
	int n = sizes.second;

	int k = 0;
	for (int i = 0; i < m - 1; ++i) {

		int ind = row_for_absmax_in_j_column_from_i_row(matr, i, i);
		if (ind != i) {

			matr.swap_rows(i, ind);
			k++;

		}

		if (matr(i, i) != 0) {

			matr.mult_i_row_by_k(i, 1 / matr(i, i));

			for (int j = i + 1; j < m; ++j) {

				matr.add_i_row_to_j_mult_by_k(i, j, -1 * (matr(j, i)));


			}

		}
		for (int k = i; k < m; ++k) {

			int ind = -1;
			for (int j = 0; (j < n) and (ind < 0); ++j) {

				if (matr(k, j) != 0) {

					ind = j;

				}

			}
			if (ind == n - 1) {

				++i;

			}

		}

	}

	for (int i = m - 1; i >= 0; i--) {

		if (matr.is_nullrow(i)) {

			matr.delete_i_row(i);

		}

	}

	return k;

}


std::vector<Fraction> basis_solution(Matr matr, std::vector<int> indexes) {

	auto size = matr.size();
	int m = size.first;
	int n = size.second;

	for (int i = 0; i < indexes.size(); ++i) {

		for (int j = 0; j < m; ++j) {

			if (j != i) {

				matr.add_i_row_to_j_mult_by_k(i, j, -1 * (matr(j, indexes[i]) / matr(i, indexes[i])));

			}


		}

	}

	std::vector<Fraction> solution(n - 1);
	int t = 0;
	for (int i = 0; i < n - 1; ++i) {

		if (std::find(indexes.begin(), indexes.end(), i) != indexes.end()) {

			solution[i] = matr(t, n - 1) / matr(t, i);
			t++;

		}
		else {

			solution[i] = 0;

		}

	}
	

	return solution;

}


int next_combination(std::vector<int>& a, int n, int m) {

	int k = m;
	for (int i = k - 1; i >= 0; --i) {

		if (a[i] < n - k + i)
		{

			++a[i];
			for (int j = i + 1; j < k; ++j)
				a[j] = a[j - 1] + 1;
			return 1;

		}

	}
	return 0;

}

std::vector<Fraction> optimize_function_with_restrictions(std::function<Fraction(std::vector<Fraction>)> f, Matr matr) {

	if (not forward_pass(matr)) {

		std::cout << "Система несовместна" << std::endl;
		return {};

	}
	std::cout << matr << std::endl;
	int number_of_basis_variables = matr.size().first;
	int number_of_variables = matr.size().second - 1;

	std::vector<int> combinations;
	for (int i = 0; i < number_of_basis_variables - 1; ++i) {

		combinations.push_back(i);

	}
	combinations.push_back(number_of_basis_variables - 2);

	std::vector<Fraction> best_solution;
	Fraction max_value(INT_MIN, 1);

	std::cout << number_of_basis_variables;
	while (next_combination(combinations, number_of_variables, number_of_basis_variables)) {

		auto solution = basis_solution(matr, combinations);

		for (int i = 0; i < solution.size(); ++i) {

			std::cout << "x_" << i + 1 << " = " << solution[i] << std::endl;

		}
		if (std::find_if(solution.begin(), solution.end(), [](Fraction a) { return a < Fraction(0); }) == solution.end()) {

			std::cout << "Данное решения является опорным" << std::endl;

		}
		std::cout << std::endl;

		Fraction res = f(solution);
		if (res > max_value) {

			max_value = res;
			best_solution = solution;

		}


	}

	return best_solution;

}