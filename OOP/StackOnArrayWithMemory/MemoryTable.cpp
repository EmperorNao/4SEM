#include "MemoryTable.h"
#include <string>


MemoryTable::MemoryTable() {

	for (ptr i = 0; i < SYSTEM_MEMORY_SIZE; i += SIZE_OF_LINK) {

		memcpy(mem + i, &EMPTY_LINK ,SIZE_OF_LINK);

	}

}


void MemoryTable::add(ptr start, ptr end) {

	ptr current = 0;
	Link l;
	while (current < ptr(SYSTEM_MEMORY_SIZE)) {

		memcpy(&l, mem + current, SIZE_OF_LINK);
		if (((l.end > 0) and (l.start > 0)) or ((l.end > 0) and (l.start == 0))) {

			current += SIZE_OF_LINK;

		}
		else {

			Link l(start, end);
			memcpy(mem + current, &l, SIZE_OF_LINK);
			return;

		}

	}

}


void MemoryTable::remove(ptr start) {

	ptr current = 0;
	Link l;
	while ((current < ptr(SYSTEM_MEMORY_SIZE))) {

		memcpy(&l, mem + current, SIZE_OF_LINK);
		if ((l.start != start)) {

			current += SIZE_OF_LINK;

		}
		else {

			memcpy(mem + current, &EMPTY_LINK, SIZE_OF_LINK);
			return;

		}

	}


}


ptr MemoryTable::get_end(ptr start) {

	ptr current = 0;
	Link l;
	while (current < ptr(SYSTEM_MEMORY_SIZE)) {

		memcpy(&l, mem + current, SIZE_OF_LINK);
		if (l.start == start) {

			return l.end;

		}
		current += SIZE_OF_LINK;

	}
	return NOT_IN_MEMORY;

}

