#include "pathfinder.h"

void mx_add_new(t_island* first, t_island* second, int length, int i) {
	if (first->name == second->name) {
		char *res = mx_itoa(i + 1);
		mx_printerr("error: line ");
                mx_printerr(res);
                mx_printerr(" is not valid\n");
                exit(0);
	}
	mx_new_way(&first->ways, second, length);
	mx_new_way(&second->ways, first, length);
}
