#include <iostream>
#include "Transport.h"
#include <locale.h>


int main() {

	setlocale(LC_ALL, "RUS");

	int m, n;
	std::cout << "Введите количество разных запасов" << std::endl;
	std::cin >> m;
	std::cout << "Введите количесто разных поставщиков" << std::endl;
	std::cin >> n;
	Matr matr(m, n);
	std::cout << "Введите матрицу стоимостей" << std::endl;
	std::cin >> matr;
	Cycle t;
	std::vector<int> needs(n);
	std::vector<int> stocks(m);
	std::cout << "Введите коэффициенты запасов" << std::endl;
	for (int i = 0; i < m; ++i) {

		std::cin >> stocks[i];

	}
	std::cout << "Введите коэффициенты потребностей" << std::endl;
	for (int i = 0; i < n; ++i) {

		std::cin >> needs[i];

	}
	int type = 1;
	std::cout << "Выберите метод решения транспортной задачи (1 - распределительный метод, \
2 - метод потенциалов)" << std::endl;
	std::cin >> type;
	Matr sol;
	switch (type)
	{
	case 1 : 
		sol = distribution_method(matr, needs, stocks);
		break;

	default:
		sol = potential_method(matr, needs, stocks);
		break;
	}
	std::cout << std::endl << "Полученная матрица перевозок " << std::endl;
	std::cout << sol;
	std::cout << "Минимальная стоимость = " << summ(matr, sol);

}