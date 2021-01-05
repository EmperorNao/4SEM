#include "Fraction.h"
#include <iostream>
#include <string>
#include <locale.h>

int main(int argc, char* argv[]) {

	setlocale(LC_ALL, "RUS");
	if (argc < 3) {

		return -1;

	}

	Fraction first_number(std::stoi(argv[1]));
	Fraction second_number(argv[2]);

	std::cout << "Сравнение двух чисел: " << std::endl;
	std::cout << first_number << " ";

	char less_or_greater = '>';
	if (first_number < second_number) {

		less_or_greater = '<';

	}
	
	std::cout << less_or_greater << " " << second_number;
	return 0;

}