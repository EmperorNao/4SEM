#include "UnimodalMinimization.h"
#include <iostream>
#include <Windows.h>

int main() {

	SetConsoleOutputCP(1251);

	std::string s;
	std::cout << "Введите функцию\n";
	std::getline(std::cin, s);
	double left, right, eps;
	std::cout << "Введите отрезон унимодальности\n";
	std::cin >> left >> right;
	std::cout << "Введите точность\n";
	std::cin >> eps;
	RationalFunction f(s);
	double x_value;
	x_value = fibonacci_optimal_search_minimization(f, left, right, eps);
	std::cout << "Метод чисел Фибоначчи:\nx_min = " << x_value << ", y_min = " << f(x_value) << std::endl;
	x_value = half_division_optimal_search_minimization(f, left, right, eps);
	std::cout << "Метод половинного деления:\nx_min = " << x_value << ", y_min = " << f(x_value) << std::endl;
	x_value = unimodal_optimal_search_minimization(f, left, right, eps);
	std::cout << "Метож оптимального поиска\nx_min = " << x_value << ", y_min = " << f(x_value) << std::endl;


}