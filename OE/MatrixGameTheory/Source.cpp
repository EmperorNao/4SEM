#include <iostream>
#include "MatrixGame.h"
#include <locale.h>


int main() {

	setlocale(LC_ALL, "RUS");
	int m, n;
	std::cout << "Введите количество строк" << std::endl;
	std::cin >> m;
	std::cout << "Введите количество столбцов" << std::endl;
	std::cin >> n;
	Matr matr(m, n);

	std::cout << "Введите расширенную матрицу ограничений" << std::endl;
	std::cin >> matr;
	std::vector<Fraction> target(n);
	std::cout << "Введите вектор коэффициентов целевой функции"<< std::endl;
	for (int i = 0; i < n; ++i) {

		std::cin >> target[i];

	}

	auto sol = dual_simplex(matr, target, false);
	auto solution = sol.first;
	auto dual_solution = sol.second;

	std::cout << std::endl <<"Решение, полученное с помощью симплекс метода: " << std::endl << std::endl;
	std::cout << "Исходная задача" << std::endl;
	std::cout << "f_max = " << solution[0] << std::endl;
	for (int i = 1; i < solution.size(); ++i) {

		std::cout << "y_" << i << " = " << solution[i] << std::endl;

	}
	std::cout << "Смешанная стратегия второго игрока в седловой точке" << std::endl;
	for (int i = 1; i < m + 1; ++i) {

		std::cout << "q_" << i << " = " << solution[i]/solution[0] << std::endl;

	}



	std::cout << std::endl <<"Двойственная задача" << std::endl;
	std::cout << "z_min = " << dual_solution[0] << std::endl;
	for (int i = 1; i < dual_solution.size(); ++i) {

		std::cout << "x_" << i << " = " << dual_solution[i] << std::endl;

	}
	std::cout << "Смешанная стратегия первого игрока в седловой точке" << std::endl;
	for (int i = 1; i < m + 1; ++i) {

		std::cout << "p_" << i << " = " << dual_solution[i] / dual_solution[0] << std::endl;

	}

}