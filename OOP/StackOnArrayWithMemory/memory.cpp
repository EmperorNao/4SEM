#include "Memory.h"


ptr Memory::first_size_long_Memory(size_t size) {

	bool current_sequense_is_empty = false;
	ptr current_start_index = 0;
	size_t current_size = 0;

	for (ptr i = 0; i < ptr(MEMORY_SIZE); ++i) {

		if (mem[i] == EMPTY_BYTE) {

			if (current_sequense_is_empty) {
				
				++current_size;

			}
			else {

				current_start_index = i;
				++current_size;
				current_sequense_is_empty = true;

			}

		}
		else {

			if (current_sequense_is_empty) {

				current_sequense_is_empty = false;

			}

		}
		if (current_size >= size) {

			return current_start_index;

		}

	}
	return NOT_ENOUGH_MEMORY;

}


ptr Memory::allocate(size_t size) {

	ptr start_position = first_size_long_Memory(size);
	if (start_position == NOT_ENOUGH_MEMORY) {

		return NOT_ENOUGH_MEMORY;

	}
	else {

		ptr end_position = start_position + ptr(size);
		for (ptr i = start_position; i < end_position; ++i) {

			mem[i] = 0;

		}
		table.add(start_position, end_position);

	}
	return start_position;

}


void Memory::free(ptr start) {

	ptr end = table.get_end(start);
	if (end != NOT_IN_MEMORY) {

		table.remove(start);
		for (ptr i = start; i < end; ++i) {

			memcpy(mem + i, &EMPTY_BYTE, sizeof(EMPTY_BYTE));

		}

	}

}


Memory::Memory() {

	for (ptr i = 0; i < MEMORY_SIZE; ++i) {

		mem[i] = EMPTY_BYTE;

	}

}

