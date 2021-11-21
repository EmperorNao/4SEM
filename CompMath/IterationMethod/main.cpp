#include "Iteration.h"
#include <locale.h>


int main() {

	setlocale(LC_ALL, "RUS");
	int m;
	std::cout << "Введите количество переменных" << std::endl;
	std::cin >> m;

	Matr matr(m, m + 1);
	std::cout << "Введите матрицу" << std::endl;
	std::cin >> matr;

	double eps;
	std::cout << "Введите точность" << std::endl;
	std::cin >> eps;
	
	std::cout << "Решение СЛАУ, полученное итерационным методом" << std::endl;
	auto solution = solve_linear_system(matr, eps);
	for (int i = 0; i < solution.size(); ++i) {

		std::cout << "x_" << i + 1 << " = " << solution[i] << std::endl;

	}


}