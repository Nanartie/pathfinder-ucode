#include "libmx.h"

void mx_pop_front(t_list **list) {
	if (list == NULL || (*list) == NULL) return;
	if ((*list)->next == NULL) {
		free(*list);
		*list = NULL;
		return;
	}
	else {
		t_list *tmp = (*list)->next;
		if (!tmp) return;
		free(*list);
		*list = tmp;
	}
}

