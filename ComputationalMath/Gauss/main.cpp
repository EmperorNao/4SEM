#include <iostream>
#include <locale.h>
#include "Gauss.h";

int main() {

	setlocale(LC_ALL, "RUS");
	int number_of_variables;

	int p;
	std::cout << "Введите порядок матриц A и B" << std::endl;
	std::cin >> p;
	Matrix<Fraction> A(p, p);
	Matrix<Fraction> B(p, p);
	std::cout << "Введите матрицу A" << std::endl;
	std::cin >> A;
	std::cout << "Введите матрицу B" << std::endl;
	std::cin >> B;

	std::cout << "(B^3 * A^2) + A равно" << std::endl;
	Matr t1 = B * B;
	Matr t2 = A * A;
	t1 = B * t1;
	t2 = t1 * t2;
	t2 = t2 + A;
	std::cout << t2;

	std::cout << "Введите количество переменных" << std::endl;
	std::cin >> number_of_variables;

	Matrix<Fraction> m(number_of_variables, number_of_variables + 1);
	std::cout << "Введите расширенную матрицу системы" << std::endl;
	std::cin >> m;

	forward_pass(m);
	std::cout << "Решение" << std::endl;	
	auto solution = back_propagation(m);
	for (int i = 0; i < solution.size(); ++i) {

		std::cout << char('x' + i) << " = "<< solution[i] << std::endl;

	}

	int n;
	std::cout << "Введите порядок матрицы, для которой нужно найти\
 определитель и обратить" << std::endl;
	std::cin >> n;
	A.resize(n, n);
	std::cout << "Введите матрицу A" << std::endl;
	std::cin >> A;
	std::cout << "det A = " << determinant(A) << std::endl;
	std::cout << "Матрица, обратная к A " << std::endl;
	std::cout << inverse(A);

}