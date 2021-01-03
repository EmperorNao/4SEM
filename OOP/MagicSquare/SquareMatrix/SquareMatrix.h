

class SquareMatrix {

protected:

	int n;
	int* m;

public:

	SquareMatrix(int size) {

		n = size;
		m = new int[n*n];

	}

	~SquareMatrix() {

		delete[] m;

	}

};