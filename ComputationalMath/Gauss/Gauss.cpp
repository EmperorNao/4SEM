#include "Gauss.h"


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

		for (int j = i + 1; j < m; ++j) {

			matr.add_i_row_to_j_mult_by_k(i, j, -1 * (matr(j, i) / matr(i, i)));

		}


	}

	return k;

}


std::vector<Fraction> back_propagation(Matr& matr, int last) {

	auto sizes = matr.size();
	int m = sizes.first;
	int n = sizes.second;
	std::vector<Fraction> p(m);

	if (last < 0) {

		last = n - 1;

	}
	
	p[m - 1] = matr(m - 1, last) / matr(m - 1, m - 1);

	for (int k = m - 2; k >= 0; --k) {

		Fraction sum = Fraction(0);

		for (int j = k + 1; j < m; ++j) {

			sum += matr(k, j) * p[j];

		}
		
		p[k] = (matr(k, last) - sum) / matr(k, k);

	}

	return p;

}


Fraction determinant(Matr matr) {

	int number_of_swaps = forward_pass(matr);
	Fraction det(1);

	auto sizes = matr.size();
	int m = sizes.first;
	int n = sizes.second;

	if (m == n) {

		for (int i = 0; i < m; ++i) {

			det *= matr(i, i);

		}

		if (number_of_swaps % 2 == 1) {

			det *= -1;

		}

	}
	
	return det;

}


Matr inverse(Matr matr) {

	auto sizes = matr.size();
	int m = sizes.first;
	int n = sizes.second;
	
	Matr new_matr(m, 2 * n);
	Matr inverse(m, n);

	if (m == n) {

		for (int i = 0; i < m; ++i) {

			for (int j = 0; j < n; ++j) {

				new_matr(i, j) = matr(i, j);

			}

		}

		for (int i = 0; i < m; ++i) {

			for (int j = n; j < 2 * n; ++j) {

				if (i + n == j) {

					new_matr(i, j) = 1;

				}
				else {

					new_matr(i, j) = 0;

				}

			}

		}

		forward_pass(new_matr);

		for (int i = n; i < 2 * n; ++i) {

			Arr col = back_propagation(new_matr, i);
			for (int j = 0; j < m; ++j) {

				inverse(j, i - n) = col[j];

			}

		}

	}

	return inverse;

}