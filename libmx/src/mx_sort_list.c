#include "libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
	if (list == NULL || cmp == NULL) return NULL;
	for (t_list *i = list; i != NULL; i = i->next) {
		for (t_list *j = list; j->next != NULL; j = j->next) {
			t_list *tmp = j;
			if (cmp(tmp->data, tmp->next->data)) {
				void *point = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = point;
			}
		}
	}
	return list;
}


