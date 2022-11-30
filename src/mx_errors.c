#include "pathfinder.h"

static void firstline_err(t_countinf *obj) {
	char **all = obj->filestruct;
	int i = -1;
	char *c = all[0];
	bool res = true;
	while (c[++i]) {
	    if (!mx_isdigit(c[i]))
	        res = false;
	    if (i !=0 && c[i] == '\n')
	    	res = true;
	}
	if (res == false) {
	    mx_printerr("error: line 1 is not valid\n");
	    mx_free_obj(obj);
	    exit(0);
	}
}

static void numb_err(t_countinf *obj) {
   char **all = obj->filestruct;
    int first = 0;
    int second = 0;
    
    for (int i = 1; all[i] != NULL; i++) {
        for (int j = 0; all[i][j] != '\0'; j++) {
            if (all[i][j] == '-')
		 first++;
	    if (first == 1 && all[i][j] == ',')
		 second++;
	}
	if (first != 1 || second != 1) {
	    char *res = mx_itoa(i + 1);
	    mx_printerr("error: line ");
            mx_printerr(res);
            mx_printerr(" is not valid\n");
            mx_free_obj(obj);
            exit(0);
        }
	first = 0;
	second = 0;
    }
}

void mx_errors(t_countinf *obj) {
	firstline_err(obj);
	mx_str_errs(obj);
	mx_line_check(obj);
	numb_err(obj);
}


