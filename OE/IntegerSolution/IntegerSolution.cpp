#include "IntegerSolution.h"
#include "Simplex.h"


Matr simplex_artificial(Matr matr, std::vector<Fraction> target, \
	std::vector<int>& basis_variables, std::vector<int>& all_variables,  bool log) {

	auto size = matr.size();
	int m = size.first;
	int n = size.second;
	std::string basis_variables_stirng = "yyy";
	std::string all_variables_string = "xxxxxx";


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

			std::cout << step << " шаг метода искусственного базиса и соответствующа€ симплекс таблица" << std::endl;
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

		std::cout << step << " шаг метода искусственного и соответствующа€ симплекс таблица" << std::endl;
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

		std::cout << std::endl << "»сходна€ таблица, приведенна€ к допустимому базисному виду" << std::endl;
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
	return res;

}


Matr simplex_(Matr matr, std::vector<int>& basis_variables, std::vector<int>& all_variables, bool log) {


	auto size = matr.size();
	int m = size.first;
	int n = size.second;

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

			std::cout << step << " шаг симплекс метода и соответствующа€ симплекс таблица" << std::endl;
			for (int i = 0; i < m; ++i) {

				if (i != m - 1) {

					std::cout << "x_" << basis_variables[i] << " ";

				}
				else {

					std::cout << "z   ";

				}
				for (int j = 0; j < n; ++j) {

					std::cout << matr(i, j) << " ";

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

		std::cout << step << " шаг симплекс метода и соответствующа€ симплекс таблица" << std::endl;
		for (int i = 0; i < m; ++i) {

			if (i != m - 1) {

				if (i < 3) {
					std::cout << "x_" << basis_variables[i] << " ";
				}
				else {
					std::cout << "u_" << 1 << " ";
				}

			}
			else {

				std::cout << "z   ";

			}
			for (int j = 0; j < n; ++j) {

				std::cout << matr(i, j) << " ";

			}

			std::cout << std::endl;


		}

	}
	return matr;

}


Matr upgrading_estimation_(Matr& matr, std::vector<int>& basis_variables, std::vector<int>& all_variables, bool log) {

	auto size = matr.size();
	int m = size.first;
	int n = size.second;

	int variable_index = -1;

	Fraction min = Fraction(0);
	for (int j = 0; (j < m - 1); ++j) {

		if (matr(j, 0) < min) {

			variable_index = j;
			min = matr(j, 0);

		}

	}


	int step = 1;
	if (log) {

		std::cout << std::endl;

	}
	while (variable_index >= 0) {

		if (log) {

			std::cout << step << " шаг двойственного симплекс метода и соответствующа€ симплекс таблица" << std::endl;
			for (int i = 0; i < m; ++i) {

				if (i != m - 1) {

					if (i < 3) {
						std::cout << "x_" << basis_variables[i] << " ";
					}
					else {
						std::cout << "u_" << 1 << " ";
					}

				}
				else {

					std::cout << "z   ";

				}
				for (int j = 0; j < n; ++j) {

					std::cout << matr(i, j) << " ";

				}

				std::cout << std::endl;


			}

		}
		int decision_index = -1;

		Fraction min_relation(INT_MAX);
		for (int j = 1; j < n; ++j) {

			bool f = (matr(variable_index, j) < Fraction(0));
			Fraction p = -1 * matr(m - 1, j) / matr(variable_index, j);
			if ((matr(variable_index, j) < Fraction(0)) and (-1 * matr(m - 1, j) / matr(variable_index, j) < min_relation)) {

				min_relation = -1 * matr(m - 1, j) / matr(variable_index, j);
				decision_index = j;

			}

		}

		if (decision_index == -1) {

			return {};

		}

		int t = variable_index;
		variable_index = decision_index;
		decision_index = t;

		basis_variables[decision_index] = variable_index;
		matr.mult_i_row_by_k(decision_index, 1 / matr(decision_index, variable_index));

		for (int i = 0; i < decision_index; ++i) {

			matr.add_i_row_to_j_mult_by_k(decision_index, i, -1 * matr(i, variable_index) / matr(decision_index, variable_index));

		}

		for (int i = decision_index + 1; i < m; ++i) {

			matr.add_i_row_to_j_mult_by_k(decision_index, i, -1 * matr(i, variable_index) / matr(decision_index, variable_index));

		}

		variable_index = -1;
		min = Fraction(0);
		for (int j = 0; (j < m - 1); ++j) {

			if (matr(j, 0) < min) {

				variable_index = j;
				min = matr(j, 0);

			}

		}

		step++;

	}

	if (log) {

		std::cout << step << " шаг двойственного симплекс метода и соответствующа€ симплекс таблица" << std::endl;
		for (int i = 0; i < m; ++i) {

			if (i != m - 1) {

				std::cout << "x_" << basis_variables[i] << " ";

			}
			else {

				std::cout << "z   ";

			}
			for (int j = 0; j < n; ++j) {

				std::cout << matr(i, j) << " ";

			}

			std::cout << std::endl;


		}

	}

	return matr;

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


bool is_positive_condition_row(Matr matr) {

	auto size = matr.size();
	int m = size.first;
	int n = size.second;

	for (int j = 1; j < n; ++j) {

		if (matr(m - 1, j) < Fraction(0)) {

			return false;

		}

	}
	return true;

}


bool is_positive_condition_column(Matr matr) {

	auto size = matr.size();
	int m = size.first;

	for (int i = 0; i < m - 1; ++i) {

		if (matr(i, 0) < Fraction(0)) {

			return false;

		}

	}
	return true;

}


bool is_integer_condition(Matr matr) {

	auto size = matr.size();
	int m = size.first;

	for (int i = 0; i < m - 1; ++i) {

		if (!(matr(i, 0).is_int())) {

			return false;

		}

	}
	return true;

}


std::vector<Fraction> gomori_algorithm(Matr _matr, std::vector<Fraction> target, bool log) {

	std::vector<int> all_variables;
	std::vector<int> basis_variables;
	//Matr matr = simplex_artificial(_matr, target, basis_variables, all_variables, log);
	auto size = _matr.size();
	int m = size.first;
	int n = size.second;

	int number_of_new_variables = m;

	Matr new_matr(m, n + number_of_new_variables);

	for (int i = 0; i < m; ++i) {

		new_matr(i, number_of_new_variables + n - 1) = _matr(i, n - 1);

	}

	for (int i = 0; i < m; ++i) {

		for (int j = 0; j < n - 1; ++j) {

			new_matr(i, j) = _matr(i, j);

		}

	}


	for (int i = n - m; i < n; ++i) {

		basis_variables.push_back(i);

	}

	for (int i = 1; i < target.size(); ++i) {

		all_variables.push_back(i);

	}

	size = new_matr.size();
	int _m = size.first;
	int _n = size.second;

	_matr = Matr(_m + 1, _n);

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

	_matr = simplex_(_matr, basis_variables, all_variables, log);
	size = _matr.size();
	_m = size.first;
	_n = size.second;
	/*
	for (int i = 1; i < target.size(); ++i) {

		all_variables.push_back(i);

	}



	for (int i = 1; i < target.size(); ++i) {

		if (not target[i]) {

			basis_variables.push_back(i);

		}

	}

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

	*/

	m = _m + 1;
	n = _n;
	if (!is_positive_condition_column(_matr)) {

		_matr = upgrading_estimation_(_matr, basis_variables, all_variables, log);

	}


	while (!is_integer_condition(_matr)) {

		auto size = _matr.size();
		int m = size.first;
		int n = size.second;
		int variable_index = -1;

		Fraction max = Fraction(INT_MIN);
		for (int j = 0; j < m - 1; ++j) {

			if (_matr(j, 0).float_part() > max ) {

				variable_index = j;
				max = _matr(j, 0).float_part();

			}

		}

		if (variable_index >= 0) {

			Matr new_matr(m + 1, n + 1);
			// fill last matrix
			for (int i = 0; i < m - 1; ++i) {

				for (int j = 0; j < n; ++j) {

					new_matr(i, j) = _matr(i, j);

				}

			}
			// fill last row
			for (int j = 0; j < n; ++j) {

				new_matr(m, j) = _matr(m - 1, j);

			}
			// fill last column
			for (int i = 0; i < m; ++i) {

				new_matr(i, n) = Fraction(0);

			}
			// fill basis var
			new_matr(m - 1, n) = Fraction(1);
			// fill basis raw
			for (int j = 0; j < n; ++j) {
			
				new_matr(m - 1, j) = -1 * _matr(variable_index, j).float_part();

			}
			basis_variables.push_back(all_variables.size() + 1);
			_matr = new_matr;

		} // end of if variable index
		else {

			break;

		}

		size = _matr.size();
		m = size.first;
		n = size.second;
		if (log) {

			std::cout << std::endl << " ћатрица после добавлени€ нового сечени€ √омори: " << std::endl;
			for (int i = 0; i < m; ++i) {

				if (i != m - 1) {

					if (i < 3) {
						std::cout << "x_" << basis_variables[i] << " ";
					}
					else {
						std::cout << "u_" << 1 << " ";
					}

				}
				else {

					std::cout << "z   ";

				}
				for (int j = 0; j < n; ++j) {

					std::cout << _matr(i, j) << " ";

				}

				std::cout << std::endl;


			}

		}

		if (!is_positive_condition_row(_matr)) {

			_matr = simplex_(_matr, basis_variables, all_variables, log);

		}

		else if (!is_positive_condition_column(_matr)) {

			upgrading_estimation_(_matr, basis_variables, all_variables, log);

		}

	} // end of while integer condition

	return form_solution(_matr, all_variables, basis_variables);

}
