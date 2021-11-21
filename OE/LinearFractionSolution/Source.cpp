#include <iostream>
#include "FractionLinearSolution.h"
#include <locale.h>

using std::vector;

int main() {

	setlocale(LC_ALL, "RUS");
	int m, n;
	std::cout << "������� ���������� ��������� � ������� �����������" << std::endl;
	std::cin >> m;
	std::cout << "������� ���������� ����������" << std::endl;
	std::cin >> n;
	Matr matr(m, n + 1);
	bool log = true;
	std::cout << "������� ����������� ������� ������� �����������" << std::endl;
	std::cin >> matr;

	std::vector<Fraction> nom(n + 1);
	//std::vector<Fraction> denom(n + 1);

	std::cout << "������� ������������ ������� ���������" << std::endl;
	for (int i = 0; i < n + 1; ++i) {

		std::cin >> nom[i];

	}
	/*
	std::cout << "������� ������������ ������� �����������" << std::endl;
	for (int i = 0; i < n + 1; ++i) {

		std::cin >> denom[i];

	}
	*/
	std::cout << std::endl;
	if (log) {

		std::cout << "�������� ������� �����������\n" << matr << std::endl;

	}

	//std::vector<Fraction> target = create_new_task(matr, nom, denom);
	/*
	matr.swap_columns(3, 4);
	matr.swap_columns(3, 5);
	matr.swap_columns(3, 6);
	*/
	std::vector<Fraction> sol = simplex_regularization(matr, nom, log);

	std::cout << std::endl <<"�������:" << std::endl;
	std::cout << "z_max = " << sol[0] << std::endl;
	for (int i = 1; i < 8; ++i) {

		std::cout << "x_" << i << " = " << sol[i] << std::endl;

	}
	std::cout << std::endl;


}