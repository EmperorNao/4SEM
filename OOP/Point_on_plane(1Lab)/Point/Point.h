#pragma once


class Point {

private:

	double x;
	double y;

public:

	// конструкторы
	Point() { x = 0; y = 0; };
	Point(double _x, double _y) : x(_x), y(_y) {};
	// статический конструктор, такое объ€вл€ение делает возможным вызов метода без создани€ объекта
	// возвращает точку в декартовых координатах по еЄ пол€рным координатам - рассто€нию r и углу a
	static Point Polar(double r, double a);	

	// геттеры/аксессоры
	double get_x() { return x; };
	double get_y() { return y; };

	// сеттеры/мутейторы
	void set_x(double _x) { x = _x; };
	void set_y(double _y) { y = _y; };

};

// функци€ возвращает рассто€ние между точками p1 и p2
double distance(Point* p1, Point* p2);


typedef bool (*condition)(Point*, Point*);
// функци€ выводит ближайшие точки из массива p_arr размера number_of_points, удовлетвор€ющие функции услови€ func
void print_nearest_points_with_condition(Point* p_arr[], int number_of_points, condition func);