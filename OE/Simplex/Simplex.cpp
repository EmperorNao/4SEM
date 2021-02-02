#include "Simplex.h"


std::vector<Fraction> simplex(Matr _matr, std::vector<int> target) {

	std::vector<int> all_variables;
	std::vector<int> basis_variables;

	for (int i = 1; i < target.size(); ++i) {

		if (target[i] == 0) {

			basis_variables.push_back(i);

		}

	}

	for (int i = 1; i < target.size(); ++i) {

		all_variables.push_back(i);

	}
	
	auto size = _matr.size();
	int _m = size.first;
	int _n = size.second;
	Matr matr(_m + 1, _n);

	for (int i = 0; i < _m; ++i) {

		for (int j = 1; j < _n; ++j) {

			matr(i, j) = _matr(i, j - 1);

		}

	}

	for (int i = 0; i < _m; ++i) {

		matr(i, 0) = _matr(i, _n - 1);

	}

	for (int i = 0; i < target.size(); ++i) {

		matr(_m, i) = Fraction(-target[i]);

	}

	int m = _m + 1;
	int n = _n;

	std::vector<Fraction> result(n - 1, Fraction(0));
	int variable_index = -1;
	for (int i = 1; (i < n) and (variable_index < 0); ++i) {

		if (matr(m - 1, i) < Fraction(0)) {

			variable_index = i;

		}

	}
	
	std::cout << matr << std::endl;
	while (variable_index > 0) {

		int decision_index = -1;
		Fraction min_relation(INT_MAX - 1);
		for (int j = 0; j < m - 1; ++j) {

			if ((matr(j, variable_index) > Fraction(0)) and (matr(j, 0)/matr(j, variable_index) < min_relation)) {

				min_relation = matr(j, variable_index);
				decision_index = j;

			}

		}

		if (decision_index == -1) {

			return {};

		}
		

		basis_variables[decision_index] = all_variables[variable_index - 1];
		for (int i = 0; i < n; ++i) {

			matr(decision_index, i) /= matr(decision_index, variable_index);

		}

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

		std::cout << matr << std::endl;

	}


	for (int i = 0; i < basis_variables.size(); ++i) {

		auto it = std::find(all_variables.begin(), all_variables.end(), basis_variables[i]);
		int pos = std::distance(all_variables.begin(), it);
		result[pos] = matr(i, 0);

	}
	
	return result;

}