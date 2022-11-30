#include "pathfinder.h"

static void checkfirst(t_countinf *obj) {

    char **all = obj->filestruct;
    
    for (int i = 1; all[i] != NULL; i++) {
    	if (all[i][0] == '-') {
    		char *res = mx_itoa(i + 1);
                mx_printerr("error: line ");
                mx_printerr(res);
                free(res);
                mx_printerr(" is not valid\n");
                mx_free_obj(obj);
                exit(0);
        }
        for (int j = 0; all[i][j] != '-'; j++) {
            if(mx_isalpha(all[i][j]) == false) { 
                char *res = mx_itoa(i + 1);
                mx_printerr("error: line ");
                mx_printerr(res);
                free(res);
                mx_printerr(" is not valid\n");
                mx_free_obj(obj);
                exit(0);
             }
         }
    }
}

static void checksec(t_countinf *obj) {
    char **all = obj->filestruct;
    int check = 0;
    for (int i = 1; all[i] != NULL; i++) {
        for (int j = 0; all[i][j] != ','; j++) {
            if(all[i][j] == '-') { 
                 check = 1;
                 j++;
             }
             if (check == 1 && !mx_isalpha(all[i][j])) {
                 char *res = mx_itoa(i + 1);
                 mx_printerr("error: line ");
                 mx_printerr(res);
                 free(res);
                 mx_printerr(" is not valid\n");
                 mx_free_obj(obj);
                 exit(0);
             }
         }
         check = 0;
    }
}

static void check_distline(t_countinf *obj) {
    char **all = obj->filestruct;
    int check = 0;
    for (int i = 1; all[i] != NULL; i++) {
        for (int j = 0; all[i][j] != '\0'; j++) {
            if (all[i][j] == ',') {
		 j++;
		 check = 1;
            }
            if ((!mx_isdigit(all[i][j]) && check == 1) 
            	|| (check == 1 && mx_isdigit(all[i][j]) && mx_atoi(&all[i][j]) < 1)) {
                 char *res = mx_itoa(i + 1);
                 mx_printerr("error: line ");
                 mx_printerr(res);
                 free(res);
                 mx_printerr(" is not valid\n");
                 mx_free_obj(obj);
                 exit(0);
            }
            check = 0;
        }
    }
}

void mx_line_check(t_countinf *obj) {
	checkfirst(obj);
	checksec(obj);
	check_distline(obj);
}
