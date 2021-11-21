#include "FractionLinearSolution.h"
#include <algorithm>


std::vector<Fraction> create_new_task(Matr& matr, \
	std::vector<Fraction> nom, std::vector<Fraction> denom) {

	std::vector<Fraction> new_target(nom.size() + 1);
	auto size = matr.size();
	int m = size.first;
	int n = size.second;

	Matr new_matr(m + 1, n + 1);

	for (int i = 0; i < new_target.size() - 1; ++i) {

		new_target[i] = nom[i];

	}
	new_target[new_target.size() - 1] = 0;

	for (int i = 0; i < m; ++i) {

		for (int j = 0; j < n - 1; ++j) {

			new_matr(i, j) = matr(i, j);

		}

	}
	for (int i = 0; i < m; ++i) {

		new_matr(i, n - 1) = -matr(i, n - 1);

	}
	for (int i = 0; i < m; ++i) {

		new_matr(i, n) = 0;

	}
	for (int j = 1; j < n; ++j) {

		new_matr(m, j - 1) = denom[j];

	}
	new_matr(m, n) = 1;
	matr = new_matr;
	return new_target;

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


std::vector<Fraction> form_source_solution(Matr matr, std::vector<int> all_variables, std::vector<int> basis_variables, int index) {

	std::vector<Fraction> result(all_variables.size() + 1, Fraction(0));
	result[0] = matr(basis_variables.size(), 0);
	for (int i = 0; i < basis_variables.size(); ++i) {

		auto it = std::find(all_variables.begin(), all_variables.end(), basis_variables[i]);
		int pos = std::distance(all_variables.begin(), it);
		if (pos + 1 != index) {
			result[pos + 1] = matr(i, 0) / matr(index, 0);
		}

	}
	return result;

}


std::vector<Fraction> simplex(Matr _matr, std::vector<Fraction> target, bool log) {

	auto size = _matr.size();
	int m = size.first;
	int n = size.second;
	std::vector<std::string> basis_variables_stirng = { "y_4", "y_6", "y_5", "u_1" };
	std::vector<std::string> all_variables_string = { "y_1", "y_2", "y_3", "y_0", "y_4", "y_6", "y_5", "u_1" };
	std::vector<int> basis_variables;
	std::vector<int> all_variables;

	for (int i = n - m; i < n; ++i) {

		basis_variables.push_back(i);

	}
	for (int i = 1; i < target.size(); ++i) {

		all_variables.push_back(i);

	}
	Matr matr(m + 1, n);

	for (int i = 0; i < m; ++i) {

		for (int j = 1; j < n; ++j) {

			matr(i, j) = _matr(i, j - 1);

		}
		matr(i, 0) = _matr(i, n - 1);

	}

	for (int i = 1; i < target.size(); ++i) {

		matr(m, i) = Fraction(-target[i]);

	}
	matr(m, 0) = Fraction(target[0]);

	m = m + 1;

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

					std::cout << basis_variables_stirng[i] << " ";


				}
				else {

					std::cout << "z_M ";

				}
				for (int j = 0; j < n; ++j) {

					std::cout << _matr(i, j) << " ";

				}

				std::cout << std::endl;


			}

		}
		step++;
		int decision_index = -1;
		Fraction min_relation(INT_MAX - 1);
		for (int j = 0; j < m - 1; ++j) {

			bool f = matr(j, variable_index) > Fraction(0);
			bool p = (matr(j, 0) / matr(j, variable_index) < min_relation);
			if ((matr(j, variable_index) > Fraction(0)) and (matr(j, 0) / matr(j, variable_index) < min_relation)) {

				min_relation = matr(j, 0) / matr(j, variable_index);
				decision_index = j;

			}

		}

		if (decision_index == -1) {

			break;

		}


		basis_variables[decision_index] = all_variables[variable_index - 1];
		matr.mult_i_row_by_k(decision_index, 1 / matr(decision_index, variable_index));

		for (int i = 0; i < decision_index; ++i) {

			matr.add_i_row_to_j_mult_by_k(decision_index, i, -1 * matr(i, variable_index) / matr(decision_index, variable_index));

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

	}
	if (log) {

		std::cout << step << " шаг симплекс метода и соответствующая симплекс таблица" << std::endl;
		for (int i = 0; i < m; ++i) {

			if (i != m - 1) {

				std::cout << basis_variables_stirng[i] << " ";


			}
			else {

				std::cout << "z_M ";

			}
			for (int j = 0; j < n; ++j) {

				std::cout << _matr(i, j) << " ";

			}

			std::cout << std::endl;


		}

	}
	return form_solution(matr, all_variables, basis_variables);

}


bool basis_column(Matr matr, int j) {

	auto size = matr.size();
	int m = size.first;
	int n = size.second;

	bool one = false;;
	for (int i = 0; i < m; ++i) {

		if (not one) {

			if (matr(i, j) == 1) {

				one = true;

			}
			else if (matr(i, j) != 0) {

				return false;

			}

		}
		else {

			if (matr(i, j) != 0) {

				return false;

			}

		}

	}
	return one;

}


std::vector<int> basis_rows(Matr matr) {

	auto size = matr.size();
	int m = size.first;
	int n = size.second;

	std::vector<int> basis;

	for (int j = 0; j < n - 1; ++j) {

		if (basis_column(matr, j)) {

			for (int i = 0; i < m; ++i) {

				if (matr(i, j) == 1) {

					basis.push_back(i);
					break;

				}

			}

		}

	}
	return basis;

}


std::vector<int> basis_columns(Matr matr) {

	auto size = matr.size();
	int m = size.first;
	int n = size.second;

	std::vector<int> basis;

	for (int i = 0; i < m; ++i) {

		for (int j = 0; j < n; ++j) {

			if ((basis_column(matr, j)) and (matr(i, j) == 1)) {

				basis.push_back(j);
				break;

			}

		}

	}

	return basis;

}


std::vector<Fraction> simplex_regularization(Matr matr, std::vector<Fraction> target, bool log) {

	auto size = matr.size();
	int m = size.first;
	int n = size.second;
	std::vector<std::string> basis_variables_stirng = {"y_1", "x_6", "y_2"};
	std::vector<std::string> all_variables_string = { "x_1", "x_2", "x_3", "x_4", "x_5", "x_6", "x_7"};
	std::vector<int> all_variables;
	std::vector<int> basis_variables;

	auto basis_r = basis_rows(matr);
	int number_of_new_variables = m - basis_r.size();

 	Matr new_matr(m, n + number_of_new_variables);

	for (int i = 0; i < m; ++i) {

		new_matr(i, number_of_new_variables + n - 1) = matr(i, n - 1);

	}

	for (int i = 0; i < m; ++i) {

		for (int j = 0; j < n - 1; ++j) {

			new_matr(i, j) = matr(i, j);

		}

	}

	int already_basis = 0;
	bool added_one = false;
	for (int i = 0; i < m; ++i) {

		added_one = false;
		for (int j = n - 1; j < n + number_of_new_variables - 1; ++j) {

			if ((j == n - 1 + already_basis) and not added_one) {

				if (std::find(basis_r.begin(), basis_r.end(), i) == basis_r.end()) {

					new_matr(i, j) = 1;
					already_basis += 1;
					added_one = true;

				}

			}
			else {

				new_matr(i, j) = 0;

			}

		}

	}

	Fraction max = *std::max_element(target.begin(), target.end());
	if (log) {

		max = 24;
		std::cout << "Было выбрано M = " << max << std::endl;

	}
	for (int i = n; i < n + number_of_new_variables; ++i) {

		basis_variables.push_back(i);
		target.push_back(-max);

	}

	already_basis = 0;
	for (int i = 0; i < m; ++i) {

		if (std::find(basis_r.begin(), basis_r.end(), i) == basis_r.end()) {

			target[0] += target[n + already_basis] * new_matr(i, n + number_of_new_variables - 1);

			for (int j = 0; j < n + number_of_new_variables - 1; ++j) {

				if (j != n - 1 + already_basis) {

					target[j + 1] -= target[n + already_basis] * new_matr(i, j);

				}

			}

			target[n + already_basis] = 0;
			already_basis += 1;

		}

	}
	if (log) {

		std::cout << "Целевая функция для M-задачи\n";
		for (int i = 0; i < target.size(); ++i) {

			std::cout << target[i] << " ";

		}
		std::cout << std::endl;

	}

	for (int i = 1; i < target.size(); ++i) {

		all_variables.push_back(i);

	
	}
	basis_variables = basis_columns(new_matr);

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

	for (int i = 1; i < target.size(); ++i) {

		_matr(_m, i) = Fraction(-target[i]);

	}
	_matr(_m, 0) = Fraction(target[0]);

	m = _m + 1;
	n = _n;
	int variable_index = -1;

	max = INT_MIN;
	for (int i = 1; (i < n); ++i) {

		if (_matr(m - 1, i) < Fraction(0)) {

			if (abs(_matr(m - 1, i)) > max) {

				max = abs(_matr(m - 1, i));
				variable_index = i;

			}

		}

	}

	int step = 1;
	std::cout << std::endl;
	while (variable_index > 0) {

		if (log) {

			std::cout << step << " шаг метода больших штрафов и соответствующая симплекс таблица" << std::endl;
			for (int i = 0; i < m; ++i) {

				if (i != m - 1) {

					std::cout << basis_variables_stirng[i] << " ";


				}
				else {

					std::cout << "z_M ";

				}
				for (int j = 0; j < n; ++j) {

					std::cout << _matr(i, j) << " ";

				}

				std::cout << std::endl;


			}

		}
		int decision_index = -1;
		Fraction min_relation(INT_MAX - 1);
		for (int j = 0; j < m - 1; ++j) {

			if ((_matr(j, variable_index) > Fraction(0)) and (_matr(j, 0) / _matr(j, variable_index) < min_relation)) {

				min_relation = _matr(j, 0) / _matr(j, variable_index);
				decision_index = j;

			}

		}

		if (decision_index == -1) {

			return {};

		}


		basis_variables_stirng[decision_index] = all_variables_string[variable_index - 1];
		basis_variables[decision_index] = all_variables[variable_index - 1];
		_matr.mult_i_row_by_k(decision_index, 1 / _matr(decision_index, variable_index));

		for (int i = 0; i < decision_index; ++i) {

			_matr.add_i_row_to_j_mult_by_k(decision_index, i, -1 * _matr(i, variable_index) / _matr(decision_index, variable_index));

		}

		for (int i = decision_index + 1; i < m; ++i) {

			_matr.add_i_row_to_j_mult_by_k(decision_index, i, -1 * _matr(i, variable_index) / _matr(decision_index, variable_index));

		}

		variable_index = -1;
		max = INT_MIN;
		for (int i = 1; (i < n); ++i) {

			if (_matr(m - 1, i) < Fraction(0)) {

				if (abs(_matr(m - 1, i)) > max) {

					max = abs(_matr(m - 1, i));
					variable_index = i;

				}

			}

		} 
		step++;

	}

	if (log) {

		std::cout << step << " шаг метода больших штрафов и соответствующая симплекс таблица" << std::endl;
		for (int i = 0; i < m; ++i) {

			if (i != m - 1) {

				std::cout << basis_variables_stirng[i] << " ";


			}
			else {

				std::cout << "z_M ";

			}
			for (int j = 0; j < n; ++j) {

				std::cout << _matr(i, j) << " ";

			}

			std::cout << std::endl;


		}

	}

	int index = -1;
	for (int i = 0; i < basis_variables_stirng.size(); ++i) {

		if (basis_variables_stirng[i] == "y_0") {

			index = i;
			break;

		}

	}

	return form_source_solution(_matr, all_variables, basis_variables, index);

}


Fraction get_target_value(std::vector<Fraction> nom,\
	std::vector<Fraction> denom, std::vector<Fraction> sol) {

	Fraction nom_num;
	Fraction denom_num;
	for (int i = 1; i < nom.size(); ++i) {

		nom_num += sol[i] * nom[i];
		denom_num += sol[i] * denom[i];

	}
	return nom_num / denom_num;

}




std::vector<Fraction> simplex_artificial(Matr matr, std::vector<Fraction> target, bool log) {

	auto size = matr.size();
	int m = size.first;
	int n = size.second;
	std::string basis_variables_stirng = "yyy";
	std::string all_variables_string = "xxxxxxx";

	std::vector<int> all_variables;
	std::vector<int> basis_variables;



	std::vector<int> new_target(target.size(), 0);

	int number_of_new_variables = m;

	Matr new_matr(m, n + number_of_new_variables);

	for (int i = 0; i < m; ++i) {

		new_matr(i, number_of_new_variables + n - 1) = matr(i, n - 1);

	}

	for (int i = 0; i < m; ++i) {

		for (int j = 0; j < n - 1; ++j) {

			new_matr(i, j) = matr(i, j);

		}

	}

	for (int i = 0; i < m; ++i) {

		for (int j = n - 1; j < n + number_of_new_variables - 1; ++j) {

			if (i == j - n + 1) {

				new_matr(i, j) = 1;

			}
			else {

				new_matr(i, j) = 0;

			}

		}

	}

	for (int i = n; i < n + number_of_new_variables; ++i) {

		basis_variables.push_back(i);
		new_target.push_back(-1);

	}
	for (int i = 0; i < m; ++i) {

		new_target[0] += new_target[n + i] * new_matr(i, n + number_of_new_variables - 1);
		for (int j = 0; j < m + number_of_new_variables - 1; ++j) {

			if (i != j - n + 1) {

				new_target[j + 1] -= new_target[n + i] * new_matr(i, j);

			}

		}

	}
	for (int j = n; j < n + number_of_new_variables; ++j) {

		new_target[j] = Fraction(0);

	}

	for (int i = 1; i < new_target.size(); ++i) {

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

	for (int i = 1; i < new_target.size(); ++i) {

		_matr(_m, i) = Fraction(-new_target[i]);

	}
	_matr(_m, 0) = Fraction(new_target[0]);

	m = _m + 1;
	n = _n;
	int variable_index = -1;

	for (int i = 1; (i < n) and (variable_index < 0); ++i) {

		if (_matr(m - 1, i) < Fraction(0)) {

			variable_index = i;

		}

	}

	int step = 1;
	std::cout << std::endl;
	while (variable_index > 0) {

		if (log) {

			std::cout << step << " шаг метода искусственного базиса и соответствующая симплекс таблица" << std::endl;
			for (int i = 0; i < m; ++i) {

				if (i != m - 1) {

					std::cout << basis_variables_stirng[i] << "_" << ((basis_variables_stirng[i] == 'x') ? \
						basis_variables[i] : ((basis_variables[i] % (n - number_of_new_variables)) + 1)) << " ";


				}
				else {

					std::cout << "f   ";

				}
				for (int j = 0; j < n; ++j) {

					std::cout << _matr(i, j) << " ";

				}

				std::cout << std::endl;


			}

		}
		int decision_index = -1;
		Fraction min_relation(INT_MAX - 1);
		for (int j = 0; j < m - 1; ++j) {

			if ((_matr(j, variable_index) > Fraction(0)) and (_matr(j, 0) / _matr(j, variable_index) < min_relation)) {

				min_relation = _matr(j, 0) / _matr(j, variable_index);
				decision_index = j;

			}

		}

		if (decision_index == -1) {

			return {};

		}


		basis_variables_stirng[decision_index] = all_variables_string[variable_index - 1];
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

	if (log) {

		std::cout << step << " шаг метода искусственного и соответствующая симплекс таблица" << std::endl;
		for (int i = 0; i < m; ++i) {

			if (i != m - 1) {

				std::cout << basis_variables_stirng[i] << "_" << basis_variables[i] << " ";


			}
			else {

				std::cout << "f   ";

			}
			for (int j = 0; j < n; ++j) {

				std::cout << _matr(i, j) << " ";

			}

			std::cout << std::endl;


		}

	}

	for (int i = 0; i < number_of_new_variables; ++i) {

		all_variables.pop_back();

	}

	Matr res(m, n - number_of_new_variables);
	for (int i = 0; i < m - 1; ++i) {

		for (int j = 0; j < n - number_of_new_variables; ++j) {

			res(i, j) = _matr(i, j);

		}

	}

	for (int i = 0; i < m - 1; ++i) {

		target[0] += target[basis_variables[i]] * _matr(i, 0);
		for (int j = 1; j < n - number_of_new_variables; ++j) {

			if (j != basis_variables[i]) {

				target[j] -= target[basis_variables[i]] * _matr(i, j);

			}

		}

	}
	for (int i = 0; i < m - 1; ++i) {

		target[basis_variables[i]] = Fraction(0);

	}
	res(m - 1, 0) = target[0];
	for (int j = 1; j < n - number_of_new_variables; ++j) {

		res(m - 1, j) = -target[j];

	}


	if (log) {

		std::cout << std::endl << "Исходная таблица, приведенная к допустимому базисному виду" << std::endl;
		for (int i = 0; i < m; ++i) {

			if (i != m - 1) {

				std::cout << "x_" << basis_variables[i] << " ";


			}
			else {

				std::cout << "z   ";

			}
			for (int j = 0; j < n - number_of_new_variables; ++j) {

				std::cout << res(i, j) << " ";

			}

			std::cout << std::endl;


		}

	}

	m = res.size().first;
	n = res.size().second;
	variable_index = -1;
	for (int i = 1; (i < n) and (variable_index < 0); ++i) {

		if (res(m - 1, i) < Fraction(0)) {

			variable_index = i;

		}

	}

	step = 1;
	std::cout << std::endl;
	while (variable_index > 0) {

		if (log) {

			if (log) {

				std::cout << step << " шаг симплекс метода и соответствующая симплекс таблица" << std::endl;
				for (int i = 0; i < m; ++i) {

					if (i != m - 1) {

						std::cout << "x_" << basis_variables[i] << " ";


					}
					else {

						std::cout << "z   ";

					}
					for (int j = 0; j < n; ++j) {

						std::cout << res(i, j) << " ";

					}

					std::cout << std::endl;


				}

			}

		}
		step++;
		int decision_index = -1;
		Fraction min_relation(INT_MAX - 1);
		for (int j = 0; j < m - 1; ++j) {

			bool f = res(j, variable_index) > Fraction(0);
			bool p = (res(j, 0) / res(j, variable_index) < min_relation);
			if ((res(j, variable_index) > Fraction(0)) and (res(j, 0) / res(j, variable_index) < min_relation)) {

				min_relation = res(j, 0) / res(j, variable_index);
				decision_index = j;

			}

		}

		if (decision_index == -1) {

			break;

		}


		basis_variables[decision_index] = all_variables[variable_index - 1];
		res.mult_i_row_by_k(decision_index, 1 / res(decision_index, variable_index));

		for (int i = 0; i < decision_index; ++i) {

			res.add_i_row_to_j_mult_by_k(decision_index, i, -1 * res(i, variable_index) / res(decision_index, variable_index));

		}

		for (int i = decision_index + 1; i < m; ++i) {

			res.add_i_row_to_j_mult_by_k(decision_index, i, -1 * res(i, variable_index) / res(decision_index, variable_index));

		}

		variable_index = -1;
		for (int i = 1; (i < n) and (variable_index < 0); ++i) {

			if (res(m - 1, i) < Fraction(0)) {

				variable_index = i;

			}

		}

	}
	if (log) {

		std::cout << step << " шаг симплекс метода и соответствующая симплекс таблица" << std::endl;
		for (int i = 0; i < m; ++i) {

			if (i != m - 1) {

				std::cout << "x_" << basis_variables[i] << " ";


			}
			else {

				std::cout << "z   ";

			}
			for (int j = 0; j < n; ++j) {

				std::cout << res(i, j) << " ";

			}

			std::cout << std::endl;


		}

	}

	return form_solution(res, all_variables, basis_variables);

}