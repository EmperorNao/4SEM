#include "MagicSquare.h"
#include <string>
#include <iostream>
#include <locale.h>


int main(int argc, char* argv[]) {

	setlocale(LC_ALL, "RUS");
	if (argc < 2) {

		return -1;

	}

	int degree = std::stoi(argv[1]);
	MagicSquare mag(degree);

	mag.fill();
	std::cout << "Магический квадрат, построенный методом террос Баше:" << std::endl;
	mag.print();

	return 0;

}