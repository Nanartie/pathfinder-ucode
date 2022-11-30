#include "pathfinder.h"

void mx_err_dist(int err, t_countinf *obj) {
	if (err > 2147483647 || err < 0) {
		mx_printerr("error: sum of bridges lengths is too big\n");
		mx_free_obj(obj);
		exit(0);
	}
}


