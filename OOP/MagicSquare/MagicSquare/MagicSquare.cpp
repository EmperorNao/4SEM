#include "MagicSquare.h"
#include <stdio.h>


int MagicSquare::reflect(int number) {

	return number % n;

}


void MagicSquare::terras_Bashe() {

	for (int i = 0; i < n * n; ++i) {

		m[i] = i;

	}

}


void MagicSquare::print() {

	int max_number = n * n;
	int number_of_digits = 0;

	int t = max_number;
	while (t > 0) {

		t /= 10;
		number_of_digits++;

	}

	for (int i = 0; i < n; ++i) {

		for (int j = 0; j < n; ++j) {

			printf("%0*d ", number_of_digits, m[i * n + j]);

		}
		printf("\n");

	}

}


void MagicSquare::fill() {

	terras_Bashe();

}