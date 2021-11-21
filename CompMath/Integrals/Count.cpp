#include <iostream>
#include "Integral.h"
#include <cmath>
#include <string>
#include <locale.h>


int main(int argc, char* argv[]) {
	
	setlocale(LC_ALL, "RUS");

	if (argc < 3) {

		double low_value;
		double high_value;
		std::string str;

		std::cout << "¬ведите формулу" << std::endl;
		std::getline(std::cin, str);
		std::cout << "¬ведите нижний и верхний пределы интегрировани€" << std::endl;
		std::cin >> low_value;
		std::cin >> high_value;
		getchar();
		RationalFunction f;
		f.set_formul(str);


		int n = -1;
		double eps = 1e-5;

		std::cout << "¬ведите метод вычислени€ интеграла" << std::endl;
		std::string method;
		std::getline(std::cin, method);
		double result = 0;
		if (method == "rectangle") {

			result = integrate_by_central_rectangles(f, low_value, high_value, n, eps);

		}
		else if (method == "trapezoid") {

			result = integrate_by_trapezoids(f, low_value, high_value, n, eps);

		}
		else if (method == "simpson") {

			result = integrate_by_parabols(f, low_value, high_value, n, eps);

		}
		else {

			result = integrate_by_gauss(f, low_value, high_value, n);

		}
		std::cout << result;

		getchar();

		return 0;

	}
	else {

		std::string str = argv[1];
		double low_value = std::stod(argv[2]);
		double high_value = std::stod(argv[3]);

		std::string method = "gauss";
		if (argc > 4) {

			method = argv[4];

		}

		int n = -1;
		if (argc > 5) {

			n = std::stoi(argv[5]);

		}

		double eps = 1e-5;
		if (argc > 6) {

			eps = std::stod(argv[6]);

		}

		RationalFunction f;
		f.set_formul(str);

		double result = 0;
		if (method == "rectangle") {

			result = integrate_by_central_rectangles(f, low_value, high_value, n, eps);

		}
		else if (method == "trapezoid") {

			result = integrate_by_trapezoids(f, low_value, high_value, n, eps);

		}
		else if (method == "simpson") {

			result = integrate_by_parabols(f, low_value, high_value, n, eps);

		}
		else {

			result = integrate_by_gauss(f, low_value, high_value, n);

		}
		std::cout << result;

	}
}