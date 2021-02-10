#include "UpgradedSimplex.h"

int main() {


	Matr matr(2, 4);
	std::cin >> matr;
	std::vector<int> target(4);
	for (int i = 0; i < 3; ++i) {

		std::cin >> target[i];

	}

	auto solution = simplex_regularization(matr, target);
	std::cout << "z_max = " << solution[0];
	for (int i = 0; i < solution.size(); ++i) {

		std::cout << "x_" << i + 1 << " = " << solution[i] << std::endl;

	}


}