#include "UpgradedSimplex.h"
#include <iostream>


//std::vector<Fraction> simplex_artificial_basis(Matr matr, std::vector<int> target);


std::vector<Fraction> simplex_regularization(Matr matr, std::vector<int> target) {

	auto size = matr.size();
	int m = size.first;
	int n = size.second;

	std::vector<int> new_target = target;
	int max = abs(*std::max_element(target.begin(), target.end()));
	max *= 10 * target.size();	
	
	Matr new_matr(m, 2 * n);
	for (int i = 0; i < n; ++i) {

		new_target.push_back(-1 * max);

	}

	for (int i = 0; i < m; ++i) {

		for (int j = n; j < 2 * n; ++j) {

			new_matr(i, j - n) = matr(i, j - n);
			if (i + n == j) {

				new_matr(i, j) = 1;

			}
			else {

				new_matr(i, j) = 0;

			}

		}

	}


	std::vector<Fraction> solution = simplex(new_matr, new_target);
	std::vector<Fraction> new_solution(target.size());

	Fraction sum = new_solution[0];
	for (int i = solution.size(); i < solution.size(); ++i) {

		new_solution[i - solution.size() + 1] = solution[i - solution.size() + 1];
		sum -= solution[i];

	}

	new_solution[0] = sum;
	return new_solution;

	


}