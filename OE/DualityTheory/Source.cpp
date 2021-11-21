#include <iostream>
#include "SequentialUpgradingEstimates.h"
#include <locale.h>

int main() {

	setlocale(LC_ALL, "RUS");
	int m, n;
	std::cout << "Введите количество уравнений" << std::endl;
	std::cin >> m;
	std::cout << "Введите количество переменных" << std::endl;
	std::cin >> n;
	n++;
	Matr matr(m, n);
	std::cout << "Введите расширенную матрицу системы " << std::endl;
	std::cin >> matr;
	std::vector<Fraction> target(matr.size().second);

	std::cout << "Введите вектор коэффициентов целевой функции, первым идёт свободный член" << std::endl;
	for (int i = 0; i < target.size(); ++i) {

		std::cin >> target[i];

	}

	auto sol = sequential_upgrading_estimates(matr, target, true);

	auto solution = sol.first;
	auto dual_solution = sol.second;

	std::cout << "Решение, полученное с помощью метода последовательного уточнения оценок: " << std::endl;
	std::cout << "Исходная задача" << std::endl;
	std::cout << "z_max = " << solution[0] << std::endl;
	for (int i = 1; i < solution.size(); ++i) {

		std::cout << "x_" << i << " = " << solution[i] << std::endl;

	}


	std::cout << std::endl;
	std::cout << "Двойственная задача" << std::endl;
	std::cout << "f_min = " << dual_solution[0] << std::endl;
	for (int i = 1; i < dual_solution.size(); ++i) {

		std::cout << "y_" << i << " = " << dual_solution[i] << std::endl;

	}

}