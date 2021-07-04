#include "UpgradedSimplex.h"
#include <locale.h>


int main() {

	setlocale(LC_ALL, "RUS");
	int m, n;
	std::cout << "¬ведите количество переменных" << std::endl;
	std::cin  >> n;
	n++;
	std::cout << "¬ведите количество уравнений" << std::endl;
	std::cin >> m;
	std::cout << "¬ведите расширенную матрицу системы ограничений" << std::endl;
	Matr matr(m, n);
	std::cin >> matr;
	std::vector<Fraction> target(n);
	for (int i = 0; i < n; ++i) {

		std::cin >> target[i];

	}

	std::cout << "ћетод больших штрафов" << std::endl;
	auto solution = simplex_regularization(matr, target, true);
	std::cout << "z_max = " << solution[0] << std::endl;
	for (int i = 1; i < solution.size() - 2; ++i) {

		std::cout << "x_" << i  << " = " << solution[i] << std::endl;

	}
	std::cout << "y_" << 2 << " = " << solution[solution.size() - 1] << std::endl;

}