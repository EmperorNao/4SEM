#include "Simplex.h"



int F(int i, std::vector<int> all_variables, std::vector<int> basis_variables) {

	int m = basis_variables.size();
	int n = all_variables.size() - m;

	if (i > n) {

		return i - n;

	}
	else {

		return m + i;

	}


}


std::vector<Fraction> form_solution(Matr matr, std::vector<int> all_variables, std::vector<int> basis_variables) {

	std::vector<Fraction> result(all_variables.size() + 1, Fraction(0));
	result[0] = matr(basis_variables.size(), 0);
	for (int i = 0; i < basis_variables.size(); ++i) {

		auto it = std::find(all_variables.begin(), all_variables.end(), basis_variables[i]);
		int pos = std::distance(all_variables.begin(), it);
		result[pos + 1] = matr(i, 0);

	}

	return result;

}


std::vector<Fraction> form_dual_solution(Matr matr, \
	std::vector<int> all_variables, std::vector<int> basis_variables) {

	std::vector<Fraction> result(all_variables.size() + 1, Fraction(0));
	result[0] = matr(basis_variables.size(), 0);
	for (int i = 0; i < all_variables.size(); ++i) {

		auto it = std::find(all_variables.begin(), all_variables.end(), F(all_variables[i], all_variables, basis_variables));
		int pos = std::distance(all_variables.begin(), it);
		result[pos + 1] = matr(basis_variables.size(), i + 1);

	}

	return result;


}


std::pair<std::vector<Fraction>, std::vector<Fraction>> simplex(Matr& _matr, std::vector<Fraction> target) {

	bool log = true;
	std::vector<int> all_variables;
	std::vector<int> basis_variables = {3, 4, 5, 6, 7};

	for (int i = 1; i < target.size(); ++i) {

		all_variables.push_back(i);

	}
	
	auto size = _matr.size();
	int _m = size.first;
	int _n = size.second;

	/*
	for (int i = 0; i < _n - 1; ++i) {

		bool f = false;
		for (int j = 0; j < _m; ++j) {

			if (abs(_matr(i, j)) and f) {
				
				f = false;
				break;

			}
			if (abs(_matr(i, j)) and (not f)) {

				_matr.mult_i_row_by_k(i, 1/_matr(i, j));
				f = true;

			}
			

		}
		if (f) {

			basis_variables.push_back(i + 1);

		}

	}
	*/

	Matr matr(_m + 1, _n);

	for (int i = 0; i < _m; ++i) {

		for (int j = 1; j < _n; ++j) {

			matr(i, j) = _matr(i, j - 1);

		}
		matr(i, 0) = _matr(i, _n - 1);

	}

	for (int i = 1; i < target.size(); ++i) {

		matr(_m, i) -= target[i];

	}
	matr(_m, 0) = target[0];

	for (int i = 0; i < _m; ++i) {

		for (int j = 0; j < basis_variables.size(); ++j) {

			if (matr(i, basis_variables[j])) {
			
				matr.mult_i_row_by_k(i, 1 / matr(i, basis_variables[j]));
				break;

			}

		}

	}


	int m = _m + 1;
	int n = _n;
	int variable_index = -1;


	for (int i = 1; (i < n) and (variable_index < 0); ++i) {

		if (matr(m - 1, i) < Fraction(0)) {

			variable_index = i;

		}

	}
	
	int step = 1;
	std::cout << std::endl;
	while (variable_index > 0) {

		if (log) {

			std::cout << step << " шаг симплекс метода и соответствующая симплекс таблица" << std::endl;
			for (int i = 0; i < m; ++i) {

				if (i != m - 1) {

					std::cout << "y_" << basis_variables[i] << " ";


				}
				else {

					std::cout << "z ";

				}
				for (int j = 0; j < n; ++j) {

					std::cout << matr(i, j) << " ";

				}

				std::cout << std::endl;


			}

		}
		int decision_index = -1;
		Fraction min_relation(INT_MAX - 1);
		for (int j = 0; j < m - 1; ++j) {

			if ((matr(j, variable_index) > Fraction(0)) and (matr(j, 0)/matr(j, variable_index) < min_relation)) {

				min_relation = matr(j, 0) / matr(j, variable_index);
				decision_index = j;

			}

		}

		if (decision_index == -1) {

			return {};

		}
		

		basis_variables[decision_index] = all_variables[variable_index - 1];
		matr.mult_i_row_by_k(decision_index, 1 / matr(decision_index, variable_index));

		for (int i = 0; i < decision_index; ++i) {

			matr.add_i_row_to_j_mult_by_k(decision_index, i,  -1 * matr(i, variable_index) / matr(decision_index, variable_index));

		}

		for (int i = decision_index + 1; i < m; ++i) {

			matr.add_i_row_to_j_mult_by_k(decision_index, i, -1 * matr(i, variable_index) / matr(decision_index, variable_index));

		}

		variable_index = -1;
		for (int i = 1; (i < n) and (variable_index < 0); ++i) {

			if (matr(m - 1, i) < Fraction(0)) {

				variable_index = i;

			}

		}
		step++;

	}

	if (log) {

		std::cout << step << " шаг симплекс метода и соответствующая симплекс таблица" << std::endl;
		for (int i = 0; i < m; ++i) {

			if (i != m - 1) {

				std::cout <<  "y_" << basis_variables[i] << " ";


			}
			else {

				std::cout << "z ";

			}
			for (int j = 0; j < n; ++j) {

				std::cout << matr(i, j) << " ";

			}

			std::cout << std::endl;


		}

	}

	_matr = matr;
	return { form_solution(matr, all_variables, basis_variables), form_dual_solution(matr, all_variables, basis_variables) };

}
