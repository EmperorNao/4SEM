#include "UnimodalMinimization.h"
#include <iostream>
#include <Windows.h>

int main() {

	SetConsoleOutputCP(1251);

	std::string s;
	std::cout << "������� �������\n";
	std::getline(std::cin, s);
	double left, right, eps;
	std::cout << "������� ������� ��������������\n";
	std::cin >> left >> right;
	std::cout << "������� ��������\n";
	std::cin >> eps;
	RationalFunction f(s);
	double x_value;
	x_value = fibonacci_optimal_search_minimization(f, left, right, eps);
	std::cout << "����� ����� ���������:\nx_min = " << x_value << ", y_min = " << f(x_value) << std::endl;
	x_value = half_division_optimal_search_minimization(f, left, right, eps);
	std::cout << "����� ����������� �������:\nx_min = " << x_value << ", y_min = " << f(x_value) << std::endl;
	x_value = unimodal_optimal_search_minimization(f, left, right, eps);
	std::cout << "����� ������������ ������\nx_min = " << x_value << ", y_min = " << f(x_value) << std::endl;


}