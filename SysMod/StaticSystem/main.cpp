#include <iostream>
#include "StaticSystem.h"
#include <windows.h>

int main () {

	SetConsoleOutputCP(1251);
	StaticSystem sys;
	int number_of_parameters;
	
		std::cout << "P = " << P << std::endl;
		std::cout << "Значения неизвестных параметров системы:" << std::endl;
		auto solution = sys.simulate();
		if (solution.size() != 0) {

			for (int i = 0; i < solution.size(); ++i) {

				double t = (solution[i] * 180 / 3.14159562) - int(solution[i] * 180 / 3.14159562);
				std::cout << "фи_" << i + 1 << " = " << int(solution[i] * 180 / 3.14159562) % 360 + t << " градусов" << std::endl;


			}

		}
		else {

			std::cout << "Система не может быть решена";

		}



}