#include <iostream>
#include "NonLinearSystemSolver.h"
#include <Windows.h>


int main() {

	SetConsoleOutputCP(1251);
	std::cout << "¬ведите количество переменных" << std::endl;
	int n;
	char c;
	scanf_s("%i%c", &n, &c);

	std::cout << "¬ведите функции системы" << std::endl;
	std::vector<RealFunction> system(n);

	for (int i = 0; i < n; ++i) {

		std::string s;
		std::getline(std::cin, s);

		system[i].set_formul(s);

	}
	std::vector<double> estimation(n);

	std::cout << \
		"¬ведите координаты точки, котора€ €вл€етс€ приближЄнным решением"\
		<< std::endl;
	std::string variables = system[0].get_variables();
	for (int i = 0; i < n; ++i) {

		std::cout << variables[i] << "_0 = ";
		std::cin >> estimation[i];

	}

	auto sol = solve_nonlinear_system(system, estimation);
	if (sol.first) {

		std::cout << "–ешение системы" << std::endl;
		for (int i = 0; i < n; ++i) {

			std::cout << variables[i] << " = " << sol.second[i] << std::endl;

		}

	}
	else {

		std::cout << \
			"–ешение не сошлось за приемлемое число итераций" << std::endl;

	}

}