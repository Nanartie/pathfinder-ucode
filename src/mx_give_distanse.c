#include "pathfinder.h"

void mx_give_distance(t_allways *way) {
	t_allways *buf = way;
	int length;
	t_way *temp;
	for (; buf != NULL; buf = buf->next) {
		if (!buf->wlength) {
			temp = buf->road;
			length = 0;
			for (; temp != NULL; temp = temp->next) {
				length += temp->length;
			}
			buf->wlength = length;
			length = 0;			
		}
	}
}


