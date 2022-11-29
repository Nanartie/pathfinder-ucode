#include "pathfinder.h"

void mx_err_dist(int err) {
	if (err > 2147483647 || err < 0) {
		mx_printerr("error: sum of bridges lengths is too big\n");
		exit(0);
	}
}


