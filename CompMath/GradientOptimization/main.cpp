#include "CrushingGradientDescent.h"
#include "Function.h"
#include <Windows.h>


int main() {


	SetConsoleOutputCP(1251);
	std::cout << "¬ведите функцию" << std::endl;
	std::string s;
	std::getline(std::cin, s);


	RationalFunction f(s);
	crushing_config conf;
	std::cout << "¬ведите начальное приближение:" << std::endl;
	std::vector<double> points(f.get_variables().size());
	for (int i = 0; i < f.get_variables().size(); ++i) {

		std::cin >> points[i];

	}
	std::string filename;
	std::cout << "¬ведите им€ файла, куда необходимо сохранить промежуточные шаги" << std::endl;
	std::cin >> filename;
	conf.filename = filename;
	conf.points = points;
	conf.logs = true;
	conf.lr = 1;
	conf.beta = 0.5;
	conf.gamma = 0.5;
	conf.eps = 10e-2;
	conf.number_steps_to_log = 1;
	auto solution = crushing_gradient_descent(f, conf);
	if (solution.first) {

		std::cout << "f = " << f(solution.second) << std::endl;
		for (int i = 0; i < solution.second.size(); ++i) {

			std::cout << "x_" << i + 1 << " = "<< solution.second[i] << std::endl;

		}

	}
	else {

		std::cout << "–ешение не было найдено";

	}


}