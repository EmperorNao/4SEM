#pragma once
#include "Array.h"


typedef array_type stack_type;
static int fill_factor = 2;
static int empty_factor = 4;


struct stack {

	// массив для хранения элементов
	Array arr;

	// текующая ёмкость стека
	size_t capacity = 1;

	// позиция вершины стека
	ptr head = -1;

	// конструктор - инициализация массива
	stack();

	// добавить элемент elem в стек
	void push(stack_type elem);

	// возвращает элемент с вершины стека и удаляет его
	stack_type pop();

	// возвращает элемент с вершины стека
	stack_type top();

	// возвращает значение истина, если стек пуст
	// иначе возвращает значение ложь
	bool empty();

};