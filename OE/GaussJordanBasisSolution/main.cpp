#include "Matrix.h"
#include "GaussBasisSolution.h"
#include <string>
#include <locale.h>


// целевая функция
Fraction count(std::vector<Fraction> v) {

	return v[0] + v[1] + v[2] + v[3] + v[4];

}


int main() {

	setlocale(LC_ALL, "RUS");
	
	int m, n;
	std::cout << "Введите количество уравнений в системе  " << std::endl;
	std::cin >> m;
	std::cout << "Введите количество переменных в системе" << std::endl;
	std::cin >> n;
	n++;
	Matrix<Fraction> matr(m, n);

	std::cout << "Введите расширенную матрицу коэфициентов системы ограничений" << std::endl;
	std::cin >> matr;

	getchar();

	std::cout << "Все базисные решения" << std::endl << std::endl;
	auto solution = optimize_function_with_restrictions(count, matr);
	if (solution.size() != 0) {

		std::cout << "Оптимальное решение среди опорных решений для целевой функции z = x_1 + x_2 + x_3 + x_4 + x_5" << std::endl;
		for (int i = 0; i < solution.size(); ++i) {

			std::cout << "x_" << i + 1 << " = " << solution[i] << std::endl;

		}

	}
	return 0;

}