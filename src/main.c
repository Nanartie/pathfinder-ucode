#include "pathfinder.h"

static t_condition *create_condition() {
	t_condition *cond = malloc(sizeof(t_condition));
	cond->first = NULL;
	cond->second = NULL;
	return cond;
}

static t_countinf *create_object(char *argv[]) {
	t_countinf *obj = malloc(sizeof(t_countinf));
	t_condition *condition = create_condition();
	obj->islands = NULL;
	obj->count = 0;
	obj->condition = condition;
	obj->filestruct = mx_file_stract(argv[1]);
	return obj;
}

int main(int argc, char *argv[]) {
	mx_file_err(argc, argv);
	t_countinf *obj = NULL;
	obj = create_object(argv);
	mx_errors(obj);
	mx_line_check(obj);
	
	mx_give_data(obj);
	mx_start_find_way(obj);
	mx_find_way(obj);
	mx_show_results(obj);
	
	free(obj->condition);
	free(obj);
	exit(0);
}
