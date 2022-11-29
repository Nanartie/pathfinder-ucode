#include "pathfinder.h"

static void inv_numbr_of_isl(t_island *buf, t_countinf *obj) {
	int count = 0;
	t_island *buf1 = buf;
	while(buf1) {
		count++;
		buf1 = buf1->next;
	}
	if (obj->count != count) {
		mx_printerr("error: invalid number of islands\n");
		exit(0);
	}
	free(buf1);
}

void mx_give_data(t_countinf *obj) {
	t_island *first = NULL;
	t_island *second = NULL;
	char** point = NULL;
	char* point2 = NULL;
	char **fromFile = obj->filestruct;
	obj->count += mx_atoi(fromFile[0]); 
	int i = 1;
	int err = 0;
	int length = 0;
	while (fromFile[i] != NULL) {
		point = mx_strsplit(fromFile[i], '-');
		first = mx_newisl(&obj->islands, mx_strdup(point[0]));
		point2 = mx_strdup(point[1]);
		mx_del_strarr(&point);
		point = mx_strsplit(point2, ',');
		mx_strdel(&point2);
		second = mx_newisl(&obj->islands, mx_strdup(point[0]));
		length = mx_atoi(point[1]);
		mx_del_strarr(&point);
		mx_add_new(first, second, length, i);
		i += 1;
		err += length;
		mx_err_dist(err);
	}
	t_island *buf = obj->islands;
	inv_numbr_of_isl(buf, obj);
    	free(fromFile);
}
