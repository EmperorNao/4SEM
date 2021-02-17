#include <iostream>
#include <locale.h>
#include "Gauss.h";
#include "Fraction.h"

int main() {

	setlocale(LC_ALL, "RUS");
	int number_of_variables;
	std::cin >> number_of_variables;

	Matrix<Fraction> m(number_of_variables, number_of_variables + 1);
	std::cout << "¬ведите расширенную матрицу системы" << std::endl;
	std::cin >> m;

	forward_pass(m);
	std::cout << "–ешение" << std::endl;	
	auto solution = back_propagation(m);
	for (int i = 0; i < solution.size(); ++i) {

		std::cout << char('x' + i) << " = "<< solution[i] << std::endl;

	}


}