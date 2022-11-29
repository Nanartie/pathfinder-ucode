#include "pathfinder.h"


void mx_show_results(t_countinf *obj) {
	t_island *island = obj->islands;
	t_allways *temp = NULL;
	for(; island != NULL; island = island->next) {
		for (int i = 0; i < obj->count; i++) {
			temp = island->allways[i];
			if (temp != NULL) {
				mx_show_res_one(temp);
			}
		}
	}

}


