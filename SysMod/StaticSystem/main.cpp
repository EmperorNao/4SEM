#include <iostream>
#include "StaticSystem.h"
#include <windows.h>

int main () {

	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "RUS");
	StaticSystem sys;
	int number_of_parameters;
	system_parameters params(8);
	
	std::cout << "¬ведите k1" << std::endl;
	params[0].name = 'a';
	std::cin >> params[0].value;

	std::cout << "¬ведите k2" << std::endl;
	params[1].name = 'b';
	std::cin >> params[1].value;

	std::cout << "¬ведите m1" << std::endl;
	params[2].name = 'c';
	std::cin >> params[2].value;

	std::cout << "¬ведите m2" << std::endl;
	params[3].name = 'd';
	std::cin >> params[3].value;

	std::cout << "¬ведите d1" << std::endl;
	params[4].name = 'e';
	std::cin >> params[4].value;

	std::cout << "¬ведите d2" << std::endl;
	params[5].name = 'f';
	std::cin >> params[5].value;

	std::cout << "¬ведите L1" << std::endl;
	params[6].name = 'g';
	std::cin >> params[6].value;

	std::cout << "¬ведите L2" << std::endl;
	params[7].name = 'u';
	std::cin >> params[7].value;
	
	std::cout << "«начени€ неизвестных параметров системы:" << std::endl;
	auto solution = sys.simulate(params);
	if (solution.size() != 0) {

		for (int i = 0; i < solution.size(); ++i) {

			std::cout << "фи_" << i + 1 << " = " << solution[i].value * 180 / 3.14159562 << " градусов" << std::endl;


		}

	}
	else {

		std::cout << "—истема не может быть решена";

	}




}