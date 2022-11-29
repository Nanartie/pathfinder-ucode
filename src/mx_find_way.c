#include "pathfinder.h"

void mx_find_way(t_countinf *obj) {	
	obj->condition->first = obj->islands;

	t_way *buf = NULL;
	t_allways *temp = NULL;
	for (; obj->condition->first != NULL; obj->condition->first = obj->condition->first->next) {
		obj->condition->second = obj->condition->first->next;
		t_island *thisfirst = obj->condition->first;
		for (; obj->condition->second != NULL; obj->condition->second = obj->condition->second->next) {
			if (obj->condition->first != obj->condition->second) {
				mx_find_temp_way(obj, obj->condition->first->allways, buf, 0);
				obj->condition->first = thisfirst;
				temp = obj->condition->first->allways[obj->condition->second->number];
				mx_give_distance(temp);
				mx_if_endresult(temp);
			}
		}
	}
}

