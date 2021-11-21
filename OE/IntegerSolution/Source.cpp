#include "IntegerSolution.h"

int main() {

	setlocale(LC_ALL, "RUS");
	int m, n;
	std::cout << "Введите количество уравнений в системе ограничений" << std::endl;
	std::cin >> m;
	std::cout << "Введите количество переменных" << std::endl;
	std::cin >> n;
	n++;
	std::cout << "Введите систему ограничений" << std::endl;
	Matr matr(m, n);
	std::cin >> matr;
	std::vector<Fraction> target(matr.size().second);
	std::cout << "Введите коэффициенты целевой функции: " << std::endl;
	for (int i = 0; i < target.size(); ++i) {

		std::cin >> target[i];

	}

		auto solution = gomori_algorithm(matr, target, true);

	std::cout << std::endl << "Решение, полученное первым алгоритмом Гомори: " << std::endl;
	std::cout << "z_max = " << solution[0] << std::endl;
	for (int i = 1; i < solution.size(); ++i) {

		std::cout << "x_" << i << " = " << solution[i] << std::endl;

	}

}