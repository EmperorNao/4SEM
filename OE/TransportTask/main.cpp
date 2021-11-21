#include <iostream>
#include "Transport.h"
#include <locale.h>


int main() {

	setlocale(LC_ALL, "RUS");

	int m, n;
	std::cout << "������� ���������� ������ �������" << std::endl;
	std::cin >> m;
	std::cout << "������� ��������� ������ �����������" << std::endl;
	std::cin >> n;
	Matr matr(m, n);
	std::cout << "������� ������� ����������" << std::endl;
	std::cin >> matr;
	Cycle t;
	std::vector<int> needs(n);
	std::vector<int> stocks(m);
	std::cout << "������� ������������ �������" << std::endl;
	for (int i = 0; i < m; ++i) {

		std::cin >> stocks[i];

	}
	std::cout << "������� ������������ ������������" << std::endl;
	for (int i = 0; i < n; ++i) {

		std::cin >> needs[i];

	}
	int type = 1;
	std::cout << "�������� ����� ������� ������������ ������ (1 - ����������������� �����, \
2 - ����� �����������)" << std::endl;
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
	std::cout << std::endl << "���������� ������� ��������� " << std::endl;
	std::cout << sol;
	std::cout << "����������� ��������� = " << summ(matr, sol);

}