#pragma once
#include "Linker.h"


static const ptr SYSTEM_MEMORY_SIZE = 1000 * SIZE_OF_LINK;
static const int NOT_IN_MEMORY = -1;


// таблица ссылок - хранит в себе ссылки на выделенные участки памяти как начало и конец
struct MemoryTable{

	// системное хранилище для записи ссылок
	unsigned char mem[SYSTEM_MEMORY_SIZE];

	// конструктор, инициализация системного хранилища
	MemoryTable();

	// добавить новую выделенную память от start до end в таблицу
	void add(ptr start, ptr end);

	// возвращает конечную позицию для выделенной памяти, которая начинается со start
	// если start нет в таблице, то возвращает NOT IN MEMORY
	ptr get_end(ptr start);

	// удаляет ссылку, которая начинается со start
	void remove(ptr start);

};