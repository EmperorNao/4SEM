#pragma once
#include "Fraction.h"
#include "Matrix.h"


typedef Matrix<int> Matr;


const int LEFT = 0;
const int TOP = 1;
const int RIGHT = 2;
const int BOTTOM = 3;


struct CycleEdge {

	int x;
	int y;
	bool sign;

	friend bool operator==(CycleEdge left, CycleEdge right) {

		return ((left.x == right.x) and (left.y == right.y));

	}

	friend bool operator!=(CycleEdge left, CycleEdge right) {

		return ((left.x != right.x) or (left.y != right.y));

	}

};




typedef std::vector<CycleEdge> Cycle;


void north_west_method_fulfill(Matr& X, std::vector<int> needs, std::vector<int> stocks);


bool _get_cycle(Matr& X, Cycle& c, int side_to_go); 


bool get_cycle(Matr& X, Cycle& c);


int summ(Matr X, Matr c);


void shift(Matr& X, Cycle& c);


Matr distribution_method(Matr coef, std::vector<int> needs, std::vector<int> stocks);


Matr potential_method(Matr coef, std::vector<int> needs, std::vector<int> stocks);


