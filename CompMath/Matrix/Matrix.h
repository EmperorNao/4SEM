#pragma once
#include <iostream>
#include <vector>
#include <algorithm>


template <typename type>
class Matrix {

	private:

		// �������, ���������� ����� m � ���������� �������� n
		std::vector<type> matr;
		int m; 
		int n; 


	public: 

		// �����������
		Matrix(int _m = 0, int _n = 0) : m(_m), n(_n) { matr.resize(_m * _n); };
		
		// ��������� �������
		void resize(int _m, int _n) {

			m = _m;
			n = _n;
			matr.resize(m * n);

		}
	
		// ���������� ������
		std::pair<int, int> size() {

			return std::make_pair(m, n);

		}

		// ���� �������
		friend std::istream& operator>>(std::istream& is, Matrix& m) {

			for (int i = 0; i < m.m; ++i) {

				for (int j = 0; j < m.n; ++j) {

					is >> m(i, j);

				}


			}
			return is;

		}

		// ����� �������
		friend std::ostream& operator<<(std::ostream& os, Matrix m) {

			for (int i = 0; i < m.m; ++i) {

				for (int j = 0; j < m.n; ++j) {

					os << m(i, j) << " ";

				}
				os << std::endl;

			}
			return os;

		}

		// ��������� � �������
		type& operator()(int i, int j) {

			if ((0 <= i) and (i < m) and (0 <= j) and (j < n)) {

				return matr[i * n + j];

			}

		}


		const type& operator()(int i, int j) const {

			if ((0 <= i) and (i = m) and (0 <= j) and (j < n)) {

				return matr[i * n + j];

			}

		}

		// ���������� ����������������� �������
		Matrix transpose() {

			Matrix new_matrix(n, m);

			for (int i = 0; i < m; ++i) {

				for (int j = 0; j < n; ++j) {

					new_matrix(j, i) = (*this)(i, j);

				}

			}

			return new_matrix;

		}

		// �������� ���������
		friend Matrix operator*(Matrix a, Matrix b) {

			Matrix new_matrix(a.m, b.n);
			if (a.n == b.m) {

				for (int i = 0; i < a.m; ++i) {

					for (int j = 0; j < a.n; ++j) {

						new_matrix(i, j) = 0;
						for (int k = 0; k < a.m; ++k) {

							new_matrix(i, j) = new_matrix(i, j) + a(i, k) * b(k, j);

						}

					}

				}

			}

			return new_matrix;

		}


		friend Matrix operator*(Matrix a, int number) {

			Matrix new_matrix(a.m, a.n);
			for (int i = 0; i < a.m; ++i) {

				for (int j = 0; j < a.n; ++j) {

					new_matrix(i, j) = number * a(i, j);

				}

			}

			return new_matrix;

		}


		friend Matrix operator*(int number, Matrix a) {

			return a * number;

		}


		friend Matrix operator+(Matrix a, Matrix b) {

			Matrix new_matrix(a.m, a.n);
			for (int i = 0; i < a.m; ++i) {

				for (int j = 0; j < a.n; ++j) {

					new_matrix(i, j) = a(i, j) + b(i, j);

				}

			}

			return new_matrix;

		}


		friend Matrix operator-(Matrix a, Matrix b) {

			Matrix new_matrix(a.m, a.n);
			for (int i = 0; i < a.m; ++i) {

				for (int j = 0; j < a.n; ++j) {

					new_matrix(i, j) = a(i, j) + b(i, j);

				}

			}

			return new_matrix;

		}


		friend std::vector<double> operator*(Matrix a, std::vector<double> b) {

			std::vector<double> new_matrix(a.m);
			if (a.m == b.size()) {

				for (int i = 0; i < a.m; ++i) {

					new_matrix[i] = 0;
					for (int j = 0; j < b.size(); ++j) {

						new_matrix[i] += a(i, j) * b[j];

					}

				}

			}
			return new_matrix;

		}


		friend std::vector<double> operator*(std::vector<double> b, Matrix a) {

			return a * b;

		}

		// ����� i � j ����� � �������
		void swap_rows(int _i, int _j) {

			type t;
			if ((0 <= _i < m) and (0 <= _j < m)) { 

				for (int i = 0; i < n; ++i) {

					t = (*this)(_i, i);
					(*this)(_i, i) = (*this)(_j, i);
					(*this)(_j, i) = t;

				}

			}

		}

		// �������� i-��� ������ �� k
		void mult_i_row_by_k(int _i, type k) {

			if ((0 <= _i) and (_i < n)) {

				for (int i = 0; i < n; ++i) {

					(*this)(_i, i) *= k;

				}

			}

		}


		// ����� i � j �������� � �������
		void swap_columns(int _i, int _j) {

			type t;
			if ((0 <= _i < n) and (0 <= _j < n)) {

				for (int i = 0; i < m; ++i) {

					t = (*this)(i, _i);
					(*this)(i, _i) = (*this)(i, _j);
					(*this)(i, _j) = t;

				}

			}

		}

		// ��������� � i��� ������, ���������� �� k, � j-���
		// ����������� ������� ��������� k � type(), ���� ���������� �����
		void add_i_row_to_j_mult_by_k(int _i, int _j, type k) {

			type t;
			if ((0 <= _i < m) and (0 <= _j < m)) {

				for (int i = 0; i < n; ++i) {

					(*this)(_j, i) += k * (*this)(_i, i);

				}

			}

		}


		// ������� i-��� ������ 
		void delete_i_row(int _i) {

			matr.erase(matr.begin() + _i * n, matr.begin() + (_i + 1) * n);
			m = m - 1;

		}


		bool is_nullrow(int _i) {

			return std::find_if(matr.begin() + _i * n, matr.begin() + (_i + 1) * n, [](type fr) { return (fr != 0); }) == matr.begin() + (_i + 1) * n;

		}


};
