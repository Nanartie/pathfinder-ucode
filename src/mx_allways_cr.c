#include "pathfinder.h"

static void *new_ways(size_t size) {
	void *pointer;
	if ((pointer = malloc(size))) {
		mx_memset(pointer, '\0', size);
	}
	return (pointer);
}

static t_way *create_way(t_island *wayFor) {
	t_way *temp = malloc(sizeof(t_way));
	temp->wayFor = wayFor;
	temp->next = NULL;
	return temp;
}

t_allways *mx_allways_cr(t_way *buf) {
	t_allways *temp = new_ways(sizeof(t_allways));
	t_way *thisw = buf;
	temp->road = create_way(buf->wayFor);
	temp->road->length = buf->length;
	temp->next = NULL;
	t_way *point = temp->road;
	for (; thisw->next != NULL; thisw = thisw->next) {
		point->next = create_way(thisw->next->wayFor);
		point->next->length = thisw->next->length;
		point = point->next;
	}
	return temp;
}


