#include "pathfinder.h"

void mx_if_endresult(t_allways *temp) {
	t_allways *buf = temp;
	int min = temp->wlength;
	for (; buf != NULL; buf = buf->next) {
		if (buf->wlength < min) {
			min = buf->wlength;
		}
		buf->res = false;
	}
	buf = temp;
	for (; buf != NULL; buf = buf->next) {
		if (buf->wlength == min) {
			buf->res = true;
		}
	}
}


