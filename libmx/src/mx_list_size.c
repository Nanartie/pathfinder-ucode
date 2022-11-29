#include "libmx.h"

int mx_list_size(t_list *list) {
	if(!list) return 0;
	int size = 0;
	while (list) {
		size++;
		list = list->next;
	}
	return size;
}

