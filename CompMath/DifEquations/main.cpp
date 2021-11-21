#include "Function.h"
#include "DifferencialEquations.h"
#include <iostream>
#include <fstream>
#include <string>


int main() {

	std::string str;
	std::getline(std::cin, str);

	RealFunction f(str);
	solution s = solve_by_modified_euler_method(f, 0.78,0.5, 1.78, 0.0001);
	std::cout << s.value << "+" << s.error << std::endl;

}