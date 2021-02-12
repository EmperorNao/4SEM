#include "UpgradedSimplex.h"
#include <locale.h>


int main() {

	setlocale(LC_ALL, "RUS");
	Matr matr(3, 7);
	std::cin >> matr;
	std::vector<int> target(7);
	for (int i = 0; i < 7; ++i) {

		std::cin >> target[i];

	}

	auto solution = simplex_regularization(matr, target);
	std::cout << "z_max = " << solution[0] << std::endl;
	for (int i = 1; i < solution.size(); ++i) {

		std::cout << "x_" << i + 1 << " = " << solution[i] << std::endl;

	}


}