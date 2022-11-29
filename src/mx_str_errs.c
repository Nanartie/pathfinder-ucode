#include "pathfinder.h"

int mx_str_errs(t_countinf *obj) {
    char **all = obj->filestruct;
    int first = 1;
    int second = 1;
    
    for (int i = 1; all[i] != NULL; i++) {
        for (int j = 0; all[i][j] != '\0'; j++) {
            if (all[i][j] == '-')
		 first = 0;
	    if (first == 0 && all[i][j] == ',')
		 second = 0;
	}
	if (first != 0 && second != 0)
		return i + 1;
	first = 1;
	second = 1;
    }
    return 0;
}

