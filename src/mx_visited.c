#include "pathfinder.h"

bool mx_visited(t_way *temp, t_island *first) {
	t_way *buf = temp;
	if (!buf) {
	    return false;
	}
	for (; buf != NULL; buf = buf->next) {
		if (buf->wayFor->name == first->name) {
			return true;
		}
	}
	return false;
}


