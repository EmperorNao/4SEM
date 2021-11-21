#include <iostream>
#include "Eigenvalue.h"
#include <locale.h>


int main() {

	setlocale(LC_ALL, "RUS");
	int m;
	
	std::cout << "������� ������� �������" << std::endl;
	std::cin >> m;
	Matr matr(m, m);
	std::cout << "������� �������" << std::endl;
	std::cin >> matr;
	auto sol = max_eigenvalue_eigenvector(matr);
	std::cout << "������������ ����������� �������� lambda = " << sol.first << std::endl;
	std::cout << "��������������� ��� ����������� ������: " << std::endl;
	for (int i = 0; i < sol.second.size(); ++i) {

		std::cout << "x_" << i + 1 << " = "<< sol.second[i] << std::endl;

	}


}