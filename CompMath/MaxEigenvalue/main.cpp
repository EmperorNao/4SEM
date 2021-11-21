#include <iostream>
#include "Eigenvalue.h"
#include <locale.h>


int main() {

	setlocale(LC_ALL, "RUS");
	int m;
	
	std::cout << "Введите порядок матрицы" << std::endl;
	std::cin >> m;
	Matr matr(m, m);
	std::cout << "Введите матрицу" << std::endl;
	std::cin >> matr;
	auto sol = max_eigenvalue_eigenvector(matr);
	std::cout << "Максимальное собственное значение lambda = " << sol.first << std::endl;
	std::cout << "Соответствующий ему собственный вектор: " << std::endl;
	for (int i = 0; i < sol.second.size(); ++i) {

		std::cout << "x_" << i + 1 << " = "<< sol.second[i] << std::endl;

	}


}