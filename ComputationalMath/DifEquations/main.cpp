#include "Function.h"
#include "DifferencialEquations.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {

	std::string str;
	std::getline(std::cin, str);

	RealFunction f(str);
	/*
	solution s = solve_by_runge_kutta_method(f, 0, 1, 2);
	std::cout << s.value << "+" << s.error << std::endl;
	s = solve_by_euler_method(f, 0, 1, 2);
	std::cout << s.value << "+" << s.error;
	*/
	std::ofstream fout;
	fout.open("New_file.txt");
	write_to_stream_values(f, fout, 0, 1, 0, 2, 0.2);
	fout.close();

}