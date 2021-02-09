#pragma once


typedef int ptr;


// ссылка - хранит в себе начальную и конечную позиции
struct Link {

	ptr start;
	ptr end;

	Link(ptr _s, ptr _e);
	Link();

};


static const size_t SIZE_OF_LINK = sizeof(Link);
static const Link EMPTY_LINK{ 0, 0 };