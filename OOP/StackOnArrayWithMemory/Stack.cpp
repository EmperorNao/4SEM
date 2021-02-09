#include "Stack.h"


stack::stack() {

	arr.resize(capacity);

}


void stack::push(stack_type elem) {

	if (head + 1 == capacity) {

		capacity *= fill_factor;
		arr.resize(capacity);

	}
	head++;
	arr.set_i(head, elem);

}


stack_type stack::pop() {

	stack_type elem = arr.get_i(head);
	--head;
	if (head * empty_factor < int(capacity)) {

		capacity /= fill_factor;
		arr.resize(capacity);

	}
	return elem;

}


stack_type stack::top() {

	return arr.get_i(head);

}


bool stack::empty() {

	return head == -1;

}