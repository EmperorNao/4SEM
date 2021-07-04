#include <iostream>
#include <locale.h>
#include "Gauss.h";
#include "Fraction.h"

int main() {

	setlocale(LC_ALL, "RUS");
	int number_of_variables, number_of_equations;
	std::cin >> number_of_equations;
	std::cin >> number_of_variables;

	Matrix<Fraction> m(number_of_equations, number_of_variables + 1);
	std::cout << "Введите расширенную матрицу системы" << std::endl;
	std::cin >> m;
	std::cout << std::endl;
	forward_pass(m);
	std::cout << "Матрица" << std::endl << m << std::endl;


}