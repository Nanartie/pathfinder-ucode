#include "pathfinder.h"

static void way_push_back(t_way **ways, t_way *way) {
	
	if (!*ways) {
		*ways = way;
		return;
	}
	t_way *buf = *ways;
	while (buf->next) {
		buf = buf->next;
	}
	
	buf->next = way;
}

static void allway_push_back(t_allways **ways, t_allways *way) {
	if (*ways == NULL || ways == NULL) {
		*ways = way;
	}
	else {
		t_allways *buf = *ways;
		while (buf->next != NULL) {
			buf = buf->next;
		}
		buf->next = way;
	}
}

static void way_pop_back(t_way **ways) {
	t_way *temp = *ways;
	if (*ways != NULL) {
		if (temp->next == NULL) {
			temp->wayFor = NULL;
			free(temp);
		}
		else {
			while (temp->next->next) {
				temp = temp->next;
			}
			temp->next->wayFor = NULL;
			free(temp->next);
			temp->next = NULL;
		}
	}
}

void mx_find_temp_way(t_countinf *obj, t_allways **allways, t_way *buf, int length) {
	t_way *temp = obj->condition->first->ways;
	if (mx_visited(buf, obj->condition->first))
		return;
	
	t_way *oldisl = malloc(sizeof(t_way));
        oldisl->wayFor = obj->condition->first;
        oldisl->next = NULL;
        oldisl->length = length;   
        way_push_back(&buf, oldisl);   
        if (obj->condition->first == obj->condition->second) {
        	t_allways *thisw = mx_allways_cr(buf);
        	allway_push_back(&allways[obj->condition->second->number], thisw);
        }
        else {
        	for (; temp != NULL; temp = temp->next) {
        		obj->condition->first = temp->wayFor;
        		mx_find_temp_way(obj, allways, buf, temp->length);
        	}
        }
        way_pop_back(&buf);
        
}

