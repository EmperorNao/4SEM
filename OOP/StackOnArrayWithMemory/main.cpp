#include <stdio.h>
#include <string.h>
#include "Memory.h"
#include "Stack.h"
#include <locale.h>
#include <iostream>


const int MAGIC_CONST = 42;


int main() {

	setlocale(LC_ALL, "RUS");
	stack s1;
	stack s2;
	
	std::cout << "Добавляем объекты в стеки" << std::endl;
	for (int t = 1; t < 10; ++t) {

		s1.push(t);
		s2.push(t * t + MAGIC_CONST);
		std::cout << "Добавляем " << t << " в первый стек и " <<\
			t * t + MAGIC_CONST << " во второй стек"<< std::endl;

	}

	std::cout << std::endl <<"Достаём объекты из стеков" << std::endl;
	
	while ((not s1.empty()) and (not s2.empty())) {

		std::cout << "Достаём " << s1.pop() << " из первого стека и " <<\
			s2.pop() << " из второго стека" << std::endl;

	}
	std::cout << std::endl;
	return 0;

}