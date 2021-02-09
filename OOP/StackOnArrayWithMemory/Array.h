#pragma once
#include "Memory.h"


typedef int array_type;


struct Array {

	// смещение в памяти
	ptr bias;
	// количество элементов
	size_t array_size;

	// конструктор для массива с количеством элементов size
	Array(size_t size);

	// конструктор для массива с одним элементов
	Array();

	// возвращает количество элементов
	size_t size();

	// изменяет размер массива на size
	void resize(size_t size);

	// установить i-тый элемент равный elem
	void set_i(ptr i, array_type elem);

	// возвращается элемент на i-той позиции
	array_type get_i(ptr i);

};