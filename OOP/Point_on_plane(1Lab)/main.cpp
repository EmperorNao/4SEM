#include "Point.h"
#include <iostream>
// отключаем предупреждения _s
#pragma warning(disable:4996)

// функция возвращает значение истина, если точка p удовлетворяет неравенству y > -x
bool inequality(Point* p) {

	return p->get_y() > -p->get_x();

}

// функция возвращает значение истина, если точки p1 и p2 лежат в разных полуплоскостях от прямой y = -x
bool condition_function(Point* p1, Point* p2) {

	return inequality(p1) xor inequality(p2);

}


int main(int argc, char* argv[]) {
	
	int number_of_points = argc - 1;
	if (number_of_points < 1) {

		return -1;

	}

	// выделение памяти и инициализация точек
	Point** p_arr = new Point* [number_of_points]; 

	int x, y;
	char c;
	printf("%i\n", number_of_points);
	for (int i = 0; i < number_of_points; ++i) {

		sscanf(argv[i + 1], "(%d%c%d)", &x, &c, &y); 
		p_arr[i] = new Point(x, y);

	} 

	print_nearest_points_with_condition(p_arr, number_of_points, condition_function);
	return 0;

}

