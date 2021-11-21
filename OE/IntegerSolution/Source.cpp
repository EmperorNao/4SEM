#include "IntegerSolution.h"

int main() {

	setlocale(LC_ALL, "RUS");
	int m, n;
	std::cout << "������� ���������� ��������� � ������� �����������" << std::endl;
	std::cin >> m;
	std::cout << "������� ���������� ����������" << std::endl;
	std::cin >> n;
	n++;
	std::cout << "������� ������� �����������" << std::endl;
	Matr matr(m, n);
	std::cin >> matr;
	std::vector<Fraction> target(matr.size().second);
	std::cout << "������� ������������ ������� �������: " << std::endl;
	for (int i = 0; i < target.size(); ++i) {

		std::cin >> target[i];

	}

		auto solution = gomori_algorithm(matr, target, true);

	std::cout << std::endl << "�������, ���������� ������ ���������� ������: " << std::endl;
	std::cout << "z_max = " << solution[0] << std::endl;
	for (int i = 1; i < solution.size(); ++i) {

		std::cout << "x_" << i << " = " << solution[i] << std::endl;

	}

}