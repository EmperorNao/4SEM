#define _USE_MATH_DEFINES
#include "Point.h"
#include <math.h>
#include <float.h>
#include <iostream>
#include <locale.h>

Point Point::Polar(double r, double a) {

	return Point(r * cos(a), r * sin(a));

}


double distance(Point* p1, Point* p2) {

	double t1 = p1->get_x() - p2->get_x();
	double t2 = p1->get_y() - p2->get_y();
	return sqrt(t1 * t1 + t2 * t2);

}


void print_nearest_points_with_condition(Point* p_arr[], int number_of_points, condition func) {

	int* used_indexes = new int [number_of_points];
	for (int i = 0; i < number_of_points; ++i) {

		used_indexes[i] = i;

	}

	double min_dist;
	int index_min;

	setlocale(LC_ALL, "RUS");
	std::cout << "ѕары наиболее близких точек, которые разделены пр€мой с уравнением y=-x" << std::endl;
	for (int i = 0; i < number_of_points; ++i) {

		min_dist = DBL_MAX;
		index_min = i;
		for (int j = 0; j < number_of_points; ++j) {

			// не нужна проверка i != j, т.к это сделает condition
			if (func(p_arr[i], p_arr[j])) {

				double dist = distance(p_arr[i], p_arr[j]);
				if (dist < min_dist) {

					min_dist = dist;
					index_min = j;

				}

			}

		}

		if (index_min != i) {

			used_indexes[i] = index_min;
			if (used_indexes[index_min] != i) {

				std::cout << "ѕерва€ точка: " << "(" << p_arr[i]->get_x() << "; " << p_arr[i]->get_y() << "); ¬тора€ точка:" \
					<< "(" << p_arr[index_min]->get_x() << "; " << p_arr[index_min]->get_y() << "); –ассто€ние между ними: " << min_dist << std::endl;

			}

		}
		else {

			std::cout << "¬се точки лежат в одной полуплоскости" << std::endl;
			break;

		}


	}

}