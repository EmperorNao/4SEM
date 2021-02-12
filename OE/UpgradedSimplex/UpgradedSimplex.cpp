#include "UpgradedSimplex.h"
#include <iostream>


//std::vector<Fraction> simplex_artificial_basis(Matr matr, std::vector<int> target);


std::vector<Fraction> simplex_regularization(Matr matr, std::vector<int> target) {

	auto size = matr.size();
	int m = size.first;
	int n = size.second;


	std::vector<int> new_target = target;
	int max = abs(*std::max_element(target.begin(), target.end()));
	max *= 2;

	std::vector<int> basis_variables;
	int number_of_new_variables = m;
	for (int i = 0; i < n; ++i) {

		bool f = false;
		for (int j = 0; j < m; ++j) {

			if (matr(j, i) and f) {

				f = false;
				break;

			}
			else if (matr(j, i) and !f) {

				f = true;

			}

		}
		if (f) {

			number_of_new_variables--;
			basis_variables.push_back(i + 1);

		}

	}

	Matr new_matr(m, n + number_of_new_variables);

	for (int i = 0; i < n; ++i) {

		new_target.push_back(-1 * max);

	}

	for (int i = 0; i < m; ++i) {

			new_matr(i, number_of_new_variables + n - 1) = matr(i, n - 1);

	}

	for (int i = 0; i < m; ++i) {

		for (int j = 0; j < n; ++j) {

			new_matr(i, j) = matr(i, j);

		}

	}
	std::cout << new_matr;
	for (int i = 0; i < m; ++i) {

		int pos = -1;
		for (int j = 0; j < basis_variables.size(); ++j) {

			if (new_matr(i, basis_variables[j]) != 0) {

				pos = basis_variables[j];
				break;

			}

		}

		for (int j = n - 1; j < n + number_of_new_variables - 1; ++j) {
			
			if (pos == 0) {
				if (i + n - 1 == j) {

					new_matr(i, j) = 1;

				}
				else {

					new_matr(i, j) = 0;

				}
			}
			else {

				new_matr(i, j) = 0;

			}

		}

	}

	std::vector<int> tmp;
	for (int i = n; i < n + number_of_new_variables; ++i) {

		tmp.push_back(i);
		basis_variables.push_back(i);
		target.push_back(-max);

	}

	std::cout << new_matr;
	for (int i = 0; i < m; ++i) {

		int pos = -1;
		for (int j = 0; j <number_of_new_variables; ++j) {

			if (new_matr(i, tmp[j]) != 0) {

				pos = tmp[j];
				break;

			}

		}

		if (pos) {

			target[0] += target[pos] * new_matr(i, n + number_of_new_variables - 1);
			for (int j = 1; j < target.size() - number_of_new_variables; ++j) {

				if (j != pos) {

					target[j] -= target[pos] * new_matr(i, j - 1);

				}

			}
			target[pos] = 0;

		}

	}

	for (int i = 0; i < target.size(); ++i) {

		std::cout << target[i] << " ";

	}
	std::cout << std::endl;


	std::vector<int> all_variables;

	for (int i = 1; i < target.size(); ++i) {

		all_variables.push_back(i);

	}

	size = new_matr.size();
	int _m = size.first;
	int _n = size.second;

	Matr _matr(_m + 1, _n);

	for (int i = 0; i < _m; ++i) {

		for (int j = 1; j < _n; ++j) {

			_matr(i, j) = new_matr(i, j - 1);

		}
		_matr(i, 0) = new_matr(i, _n - 1);

	}

	for (int i = 0; i < target.size(); ++i) {

		_matr(_m, i) = Fraction(-target[i]);

	}

	m = _m + 1;
	n = _n;
	int variable_index = -1;

	std::cout << _matr;
	for (int i = 1; (i < n) and (variable_index < 0); ++i) {

		if (_matr(m - 1, i) < Fraction(0)) {

			variable_index = i;

		}

	}

	int step = 1;
	std::cout << std::endl;
	while (variable_index > 0) {

		std::cout << step << " шаг симплекс метода и соответствующая симплекс таблица" << std::endl;
		std::cout << _matr << std::endl;
		int decision_index = -1;
		Fraction min_relation(INT_MAX - 1);
		for (int j = 0; j < m - 1; ++j) {

			if ((_matr(j, variable_index) > Fraction(0)) and (_matr(j, 0) / _matr(j, variable_index) < min_relation)) {

				min_relation = _matr(j, variable_index);
				decision_index = j;

			}

		}

		if (decision_index == -1) {

			return {};

		}


		basis_variables[decision_index] = all_variables[variable_index - 1];
		_matr.mult_i_row_by_k(decision_index, 1 / _matr(decision_index, variable_index));

		for (int i = 0; i < decision_index; ++i) {

			_matr.add_i_row_to_j_mult_by_k(decision_index, i, -1 * _matr(i, variable_index) / _matr(decision_index, variable_index));

		}

		for (int i = decision_index + 1; i < m; ++i) {

			_matr.add_i_row_to_j_mult_by_k(decision_index, i, -1 * _matr(i, variable_index) / _matr(decision_index, variable_index));

		}

		variable_index = -1;
		for (int i = 1; (i < n) and (variable_index < 0); ++i) {

			if (_matr(m - 1, i) < Fraction(0)) {

				variable_index = i;

			}

		}
		step++;

	}
	std::cout << step << " шаг симплекс метода и соответствующая симплекс таблица" << std::endl;
	std::cout << _matr << std::endl;

	std::vector<Fraction> solution = form_solution(_matr, all_variables, basis_variables);

	std::vector<Fraction> new_solution(n - number_of_new_variables + 1);

	Fraction sum = solution[0];

	for (int i = 1; i < new_solution.size(); ++i) {

		new_solution[i] = solution[i];

	}
	for (int i = new_solution.size(); i < solution.size(); ++i) {

		sum -= solution[i];

	}

	new_solution[0] = sum;
	return new_solution;

}