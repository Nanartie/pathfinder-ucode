#include "pathfinder.h"

void mx_file_err(int argc, char *argv[]) {
 	if (argc != 2) {
		mx_printerr("usage: ./pathfinder [filename]\n");
		exit(0);
	}
	int fd = open(argv[1], O_RDONLY);
	char *str = mx_file_to_str(argv[1]);
	if (fd < 0) {
		mx_printerr("error file ");
		mx_printerr(argv[1]);
		mx_printerr(" does not exist\n");
		exit(0);
	}
	else if (str == NULL) {
		mx_printerr("error: file ");
		mx_printerr(argv[1]);
		mx_printerr(" is empty\n");
		close(fd);
		exit(0);
	}
	free(str);
}


