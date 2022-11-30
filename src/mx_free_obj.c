#include "pathfinder.h"

void mx_free_obj(t_countinf *obj) {
	free(obj->condition->first);
	free(obj->condition->second);
	int i = 0;
	while(obj->filestruct[i] != NULL) {
		free(obj->filestruct[i]);
		i++;
	}
	free(obj->condition);
	free(obj->filestruct);
	free(obj);
}


