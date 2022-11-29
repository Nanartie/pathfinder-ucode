#include "pathfinder.h"

void mx_start_find_way(t_countinf *obj) {
	t_island *buf = obj->islands;
	int i = 0;
	while (buf) {
		buf->number = i;
		buf->allways = malloc(sizeof(t_allways *) * obj->count);
		for (int i = 0; i < obj->count; i++) {
			buf->allways[i] = NULL;
		}
		i++;
		buf = buf->next;
	}
}
