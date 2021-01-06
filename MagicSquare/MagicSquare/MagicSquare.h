#include "SquareMatrix.h"


class MagicSquare : SquareMatrix {

private:

	// правило отражения
	int reflect(int number);

	// заполнение методом террас Баше
	void terras_Bashe();

public:

	MagicSquare(int n): SquareMatrix(n) { }
	
	// отображение квадрата с лидирующими нулями в числами
	void print();

	// заполнение квадрата
	void fill();


};