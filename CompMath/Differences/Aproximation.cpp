#include <iostream>
#include <locale.h>
#include "Difference.h"

int main() {

	setlocale(LC_ALL, "RUS");
	double x;
	double number_of_values;
	std::cout << "¬ведите количество точек" << std::endl;
	std::cin >> number_of_values;
	std::cout << "¬ведите пары: точка и значение в ней" << std::endl;
	std::vector<double> points(number_of_values);
	std::vector<double> values(number_of_values);
	for (int i = 0; i < number_of_values; ++i) {

		std::cin>> points[i];
		std::cin >> values[i];	

	}
	std::cout << "¬ведите точку, в которой нужно вывести значение многочлена" << std::endl;
	std::cin >> x;
	bool fin;
	std::cout << "¬ведите 1, если нужно считать конечные разности, или введите 0, если нужно считать разделенные разности" << std::endl;
	std::cin >> fin;
	std::cout << "f(" << x << ") = "<< calculate_poly_with_n_knots_in_x(points, values, x, fin);

}