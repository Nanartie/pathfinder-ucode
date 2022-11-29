#include "pathfinder.h"

char **mx_file_stract(char *filename) {
	char *all = NULL;
	all = mx_file_to_str(filename);
	char **obj = NULL;
	obj = mx_strsplit(all, '\n');
	mx_strdel(&all);
	free(all);
	return obj;
}

