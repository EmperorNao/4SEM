#include <iostream>
#include "ArithmeticalExpression.h"
#include "Simplex.h"

int main() {
		
	int m, n;
	std::cin >> m;
	std::cin >> n;
	Matr matr(m, n);
	std::cin >> matr;
	std::vector<int> target(matr.size().second);

	for (int i = 0; i < target.size(); ++i) {

		std::cin >> target[i];

	}

	auto solution = simplex(matr, target);

	for (int i = 0; i < solution.size(); ++i) {

		std::cout << "x_" << i+1  << " = " << solution[i] << std::endl;

	}

}