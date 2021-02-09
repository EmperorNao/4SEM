#include "Array.h"


Array::Array(size_t _size) {

	array_size = _size;
	bias = MEMORY.allocate(_size * sizeof(array_type));

}


Array::Array() {

	array_size = 1;
	bias = MEMORY.allocate(sizeof(array_type));

}


size_t Array::size() {

	return array_size;

}

	
void Array::resize(size_t _size) {

	ptr new_bias = MEMORY.allocate(_size * sizeof(array_type));
	if (new_bias != NOT_ENOUGH_MEMORY) {

		array_size = _size;
		memcpy(MEMORY.mem + new_bias, MEMORY.mem + bias, \
			array_size * sizeof(array_type));
		MEMORY.free(bias);
		bias = new_bias;

	}

}


void Array::set_i(ptr i, array_type elem) {

	memcpy(MEMORY.mem + bias + i*sizeof(array_type), &elem, \
		sizeof(array_type));

}


array_type Array::get_i(ptr i) {

	array_type elem;
	memcpy(&elem, MEMORY.mem + bias + i*sizeof(array_type), \
		sizeof(array_type));
	return elem;

}