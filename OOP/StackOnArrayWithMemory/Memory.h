#pragma once
#include <iostream>
#include "MemoryTable.h"


static const size_t MEMORY_SIZE = 10000 * sizeof(ptr);
static const unsigned char EMPTY_BYTE = UCHAR_MAX;
static const int NOT_ENOUGH_MEMORY = -1;


struct Memory {

	// хранилище
	unsigned char mem[MEMORY_SIZE];
	// таблица выделенной памяти
	MemoryTable table;

	// конструктор с инициализацией хранилища
	Memory();

	// возвращает смещение первого участка памяти размера size
	// или возвращает NOT_ENOUGH_MEMORY, если такого нет
	ptr first_size_long_Memory(size_t size);

	// выделяет память для участка памяти размера size
	ptr allocate(size_t size);

	// освобождает память для участка, который начинается со смещения start
	void free(ptr start);

};


// глобальная память
static Memory MEMORY;