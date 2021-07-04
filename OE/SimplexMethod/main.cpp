#include <iostream>
#include "ArithmeticalExpression.h"
#include "Simplex.h"
#include <locale.h>

int main() {
		
	setlocale(LC_ALL, "RUS");
	int m, n;
	std::cout << "¬ведите количество уравнений" << std::endl;
	std::cin >> m;
	std::cout << "¬ведите количество переменных" << std::endl;
	std::cin >> n;
	n++;
	Matr matr(m, n);
	std::cout << "¬ведите расширенную матрицу системы " << std::endl;
	std::cin >> matr;
	std::vector<Fraction> target(matr.size().second);

	std::cout << "¬ведите вектор коэффициентов целевой функции, первым идЄт свободный член" << std::endl;
	for (int i = 0; i < target.size(); ++i) {

		std::cin >> target[i];

	}

	auto solution = simplex(matr, target);

	std::cout << "–ешение, полученное с помощью симплекс метода: " << std::endl;
	std::cout << "z_max = " << solution[0] << std::endl;
	for (int i = 1; i < solution.size(); ++i) {

		std::cout << "x_" << i  << " = " << solution[i] << std::endl;

	}

}