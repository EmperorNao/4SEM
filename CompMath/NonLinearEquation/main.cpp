#include <iostream>
#include "Function.h"
#include "NonLinearEquationSolver.h"
#include <Windows.h>


int main() {

	SetConsoleOutputCP(1251);
	std::string s;
	std::cout << "������� ���������" << std::endl;
	std::getline(std::cin, s);
	RationalFunction func(s);
	double left, right;
	std::cout << "������� �������� ������ ������" << std::endl;
	std::cin >> left >> right;
	double eps;
	std::cout << "������� ��������" << std::endl;
	std::cin>> eps;
	auto solution = solve_nonlinear_equation(func, left, right, eps);
	if (solution.first) {

		std::cout << "�������\nx = ";
		std::cout << solution.second;

	}
	else {

		std::cout << "������� �� ���� ������� �� ���������� ����� �����";

	}


}
