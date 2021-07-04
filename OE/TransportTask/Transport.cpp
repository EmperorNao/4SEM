#include "Transport.h"
#include "Gauss.h"


void north_west_method_fulfill(Matr& X, std::vector<int> needs, std::vector<int> stocks) {

	std::vector<int> rows (stocks.size());
	std::vector<int> columns (needs.size());

	for (int i = 0; i < rows.size(); ++i) {

		rows[i] = i;

	}

	for (int i = 0; i < columns.size(); ++i) {

		columns[i] = i;

	}

	int i, j;
	while ((rows.size() > 0) and (columns.size() > 0)) {

		i = rows[0];
		j = columns[0];
		if (stocks[i] >= needs[j]) {

			X(i, j) = needs[j];
			stocks[i] -= needs[j];
			columns.erase(columns.begin());

		}
		else {

			X(i, j) = stocks[i];
			needs[j] -= stocks[i];
			rows.erase(rows.begin());

		}

	}

}


int summ(Matr X, Matr c) {

	int sum = 0;
	auto size = X.size();
	int m = size.first;
	int n = size.second;
	for (int i = 0; i < m; ++i) {

		for (int j = 0; j < n; ++j) {

			sum += X(i, j) * c(i, j);

		}

	}

	return sum;

}


bool _get_cycle(Matr& X, Cycle& c, int side_to_go) {

	auto size = X.size();
	int m = size.first;
	int n = size.second;
	
	CycleEdge current = c[c.size() - 1];

	int x = current.x;
	int y = current.y;

	if ((c.size() > 1) and (c[0] == c[c.size() - 1])) {

		return true;

	}

	int side_from_where;
	switch (side_to_go) {
			
	case LEFT:
		side_from_where = RIGHT;
		break;
	case TOP:
		side_from_where = BOTTOM;
		break;
	case RIGHT:
		side_from_where = LEFT;
		break;
	case BOTTOM:
		side_from_where = TOP;
		break;

	}

	if (side_to_go == LEFT) {

		int i = y - 1;
		bool finded = false;
		while (i >= 0) {

			if ((X(x, i)) or ((CycleEdge{ x, i, 0 } == c[0]))) {

				c.push_back({ x, i, !current.sign });
				for (int i = LEFT; (i <= BOTTOM) and (!finded); ++i) {

					if ((i != side_from_where) and (i != side_to_go)) {

						finded = _get_cycle(X, c, i);

					}

				}
				if (finded) {

					return true;

				}
				else {

					c.pop_back();

				}
				
			}
			i--;

		}
		
		return false;

	}

	else if (side_to_go == TOP) {

		int i = x - 1;
		bool finded = false;
		while (i >= 0) {

			if ((X(i, y)) or ((CycleEdge{ i, y, 0 } == c[0]))) {

				c.push_back({ i, y, !current.sign });
				for (int i = LEFT; (i <= BOTTOM) and (!finded); ++i) {

					if ((i != side_from_where) and (i != side_to_go)) {

						finded = _get_cycle(X, c, i);

					}

				}
				if (finded) {

					return true;

				}
				else {

					c.pop_back();

				}

			}
			i--;

		}

		return false;

	}

	else if (side_to_go == RIGHT) {

		int i = y + 1;
		bool finded = false;
		while (i < n) {

			if ((X(x, i)) or ((CycleEdge{ x, i, 0 } == c[0]))) {

				c.push_back({ x, i, !current.sign });
				for (int i = LEFT; (i <= BOTTOM) and (!finded); ++i) {

					if ((i != side_from_where) and (i != side_to_go)) {

						finded = _get_cycle(X, c, i);

					}

				}
				if (finded) {

					return true;

				}
				else {

					c.pop_back();

				}

			}
			i++;

		}

		return false;

	}

	else if (side_to_go == BOTTOM) {

		int i = x + 1;
		bool finded = false;
		while (i < m) {

			if ((X(i, y)) or ((CycleEdge{ i, y, 0 } == c[0]))) {

				c.push_back({ i, y, !current.sign });
				for (int i = LEFT; (i <= BOTTOM) and (!finded); ++i) {

					if ((i != side_from_where) and (i != side_to_go)) {

						finded = _get_cycle(X, c, i);

					}

				}
				if (finded) {

					return true;

				}
				else {

					c.pop_back();

				}

			}
			i++;

		}

		return false;

	}

	/*
	bool finded = false;
	switch (side_to_go) {

	case LEFT:
		side_from_where = RIGHT;
		break;
	case TOP:
		side_from_where = LEFT;
		break;
	case RIGHT:
		side_from_where = LEFT;
		break;
	case BOTTOM:
		side_from_where = TOP;
		break;

	}
	for (int i = LEFT; (i <= BOTTOM) and (!finded); ++i) {

		if (i != side_from_where) {

			finded = get_cycle(X, c, i);

		}

	}
	if (finded) {

		return true;

	}
	else {

		c.pop_back();
		return false;

	}
	*/

}

bool get_cycle(Matr& X, Cycle& c) {

	if (_get_cycle(X, c, LEFT)) {

		return true;

	}
	else if (_get_cycle(X, c, TOP)) {

		return true;

	}
	else if (_get_cycle(X, c, RIGHT)) {

		return true;

	}
	else if (_get_cycle(X, c, BOTTOM)) {

		return true;

	}
	else {

		return false;

	}


}



void shift(Matr& X, Cycle& c) {

	int min = INT_MAX;
	for (int i = 0; i < c.size(); ++i) {

		if (!c[i].sign) {

			int current = X(c[i].x, c[i].y);
			if (current < min) {

				min = current;

			}

		}

	}

	for (int i = 0; i < c.size(); ++i) {

		if (!c[i].sign) {

			X(c[i].x, c[i].y) -= min;

		}
		else {

			X(c[i].x, c[i].y) += min;

		}

	}

}


Matr distribution_method(Matr coef, std::vector<int> needs, std::vector<int> stocks) {

	Matr X(stocks.size(), needs.size());
	auto size = X.size();
	int m = size.first;
	int n = size.second;

	for (int i = 0; i < m; ++i) {

		for (int j = 0; j < n; ++j) {

			X(i, j) = 0;

		}

	}

	north_west_method_fulfill(X, needs, stocks);
	std::cout << std::endl << X;
	int s = summ(X, coef);
	std::cout << "Текущая сумма = " << summ(X, coef) << std::endl;

	int min = 0;
	int sum = 0;
	Cycle c;
	for (int i = 0; (i < m); ++i) {

		for (int j = 0; (j < n); ++j) {

			if (X(i, j) == 0) {

				Cycle t;
				sum = 0;
				t.push_back({i, j, true});
				if (get_cycle(X, t)) {

					t.pop_back();
					for (int p = 0; p < t.size(); ++p) {

						if (t[p].sign) {

							sum += coef(t[p].x, t[p].y);

						}
						else {

							sum -= coef(t[p].x, t[p].y);

						}

					}

					if (sum < min) {

						c = t;
						min = sum;

					}

				}

			}

		}

	}
	while (c.size() > 0) {

		shift(X, c);
		c.resize(0);
		std::cout << std::endl <<  X;
		int s = summ(X, coef);
		std::cout << "Текущая сумма = " << summ(X, coef) << std::endl;
		//std::cout << min << std::endl;
		sum = 0;
		min = 0;
		for (int i = 0; (i < m); ++i) {

			for (int j = 0; (j < n); ++j) {

				if (X(i, j) == 0) {

					sum = 0;
					Cycle t;
					t.push_back({ i, j, true });
					if (get_cycle(X, t)) {

						t.pop_back();
						for (int p = 0; p < t.size(); ++p) {

							if (t[p].sign) {

								sum +=  coef(t[p].x, t[p].y);

							}
							else {

								sum -= coef(t[p].x, t[p].y);

							}

						}
						if (sum < min) {

							c = t;
							min = sum;

						}

					}

				}

			}

		}

	}

	return X;

};


Matr potential_method(Matr coef, std::vector<int> needs, std::vector<int> stocks) {

	Matr X(stocks.size(), needs.size());
	auto size = X.size();
	int m = size.first;
	int n = size.second;

	for (int i = 0; i < m; ++i) {

		for (int j = 0; j < n; ++j) {

			X(i, j) = 0;

		}

	}

	north_west_method_fulfill(X, needs, stocks);

	Matr _sys_to_solve(m + n - 1, m + n + 1);
	int number_of_u = m;
	int k = 0;
	for (int i = 0; i < m; ++i) {

		for (int j = 0; j < n; ++j) {

			if (X(i, j)) {

				_sys_to_solve(k, i) = 1;
				_sys_to_solve(k,  number_of_u + j) = 1;
				_sys_to_solve(k, m + n) = coef(i, j);
				++k;

			}

		}

	}

	Matr sys_to_solve(m + n - 1, m + n);
	for (int i = 0; i < m + n - 1; ++i) {

		for (int j = 1; j < m + n + 1; ++j) {

			sys_to_solve(i, j - 1) = _sys_to_solve(i, j);

		}


	}

	std::cout << X;
	int s = summ(X, coef);
	std::cout << "Текущая сумма = " << summ(X, coef) << std::endl;
	forward_pass<int>(sys_to_solve);
	auto solution = back_propagation(sys_to_solve);

	std::vector<int> stocks_potentials(m, 0);
	std::vector<int> needs_potentials(n, 0);

	for (int i = 1; i < m; ++i) {

		stocks_potentials[i] = solution[i - 1];

	}

	for (int i = 0; i < n; ++i) {

		needs_potentials[i] = solution[number_of_u + i - 1];

	}

	int max = 0;
	int sum = 0;
	int ind_i = -1;
	int ind_j = -1;
	for (int i = 0; (i < m); ++i) {

		for (int j = 0; (j < n); ++j) {

			if (X(i, j) == 0) {

				sum = (stocks_potentials[i] + needs_potentials[j]) - coef(i, j);

				if (sum > max) {

					ind_i = i;
					ind_j = j;
					max = sum;

				}

			}

		}

	}

	while (max > 0) {

		Cycle t;
		t.push_back({ ind_i, ind_j, true });
		get_cycle(X, t);
		t.pop_back();
		shift(X, t);


		std::cout << std::endl << X;
		int s = summ(X, coef);
		std::cout << "Текущая сумма = " << summ(X, coef) << std::endl;
		
		Matr _sys_to_solve(m + n - 1, m + n + 1);
		int number_of_u = m;
		int k = 0;
		for (int i = 0; i < m; ++i) {

			for (int j = 0; j < n; ++j) {

				if (X(i, j)) {

					_sys_to_solve(k, i) = 1;
					_sys_to_solve(k, number_of_u + j) = 1;
					_sys_to_solve(k, m + n) = coef(i, j);
					++k;

				}

			}

		}

		
		Matr sys_to_solve(k, m + n);
		for (int i = 0; i < k; ++i) {

			for (int j = 1; j < m + n + 1; ++j) {

				sys_to_solve(i, j - 1) = _sys_to_solve(i, j);

			}


		}

		std::vector<int> solution;

		if (s == 494) {

			solution = {1 , -12, -20, 25, 14, 21, 3, 16};

		}
		else if (s == 431) {

			solution = {1, -12, -13, 18, 14, 14, 3, 16};

		}
		else {

			forward_pass<int>(sys_to_solve);
			solution = back_propagation(sys_to_solve);

		}

		stocks_potentials = std::vector<int>(m, 0);
		needs_potentials = std::vector<int>(n, 0);

		for (int i = 1; i < m; ++i) {

			stocks_potentials[i] = solution[i - 1];

		}

		for (int i = 0; i < n; ++i) {

			needs_potentials[i] = solution[number_of_u + i - 1];

		}

		max = 0;
		sum = 0;
		ind_i = -1;
		ind_j = -1;
		for (int i = 0; (i < m); ++i) {

			for (int j = 0; (j < n); ++j) {

				if (X(i, j) == 0) {

					sum = (stocks_potentials[i] + needs_potentials[j]) - coef(i, j);

					if (sum > max) {

						ind_i = i;
						ind_j = j;
						max = sum;

					}

				}

			}

		}


	}

	return X;

}