#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

typedef struct s_island t_island;
typedef struct s_way t_way;
typedef struct s_countinf t_countinf;
typedef struct s_allways t_allways;
typedef struct s_condition t_condition;

struct s_island {
	char* name;
	t_way *ways;
	t_island *next;
	t_allways **allways;
	int number;
};

struct s_way {
	int length;
	t_island *wayFor;
	t_way *next;
};

struct s_allways {
	int wlength; 
	t_way *road;
	bool res;
	t_allways *next;	
};

struct s_condition {
	t_island *first;
	t_island *second;
	int length;
};

struct s_countinf {
	t_island *islands;
	int count;
	t_condition *condition;
	char **filestruct;
};

int mx_str_errs(t_countinf *obj);
int mx_findsize(const char *filename);
char **mx_file_stract(char *filename);
void mx_errors(t_countinf *obj);
void mx_line_check(t_countinf *obj);
void mx_give_data(t_countinf *obj);
void mx_add_new(t_island* first, t_island* second, int length, int i);
t_island* mx_newisl(t_island** islnds, char* isl);
t_island* mx_newisl_cr(char* isl);
bool mx_visited(t_way *temp, t_island *first);
void mx_give_distance(t_allways *way);
void mx_start_find_way(t_countinf *obj);
void mx_find_way(t_countinf *obj);
void mx_show_results(t_countinf *obj);
t_allways *mx_allways_cr(t_way *buf);
void mx_find_temp_way(t_countinf *obj, t_allways **allways, t_way *buf, int length);
void mx_if_endresult(t_allways *temp);
void mx_file_err(int argc, char *argv[]);
void mx_new_way(t_way **ways, t_island *second, int length);
void mx_show_res_one(t_allways *temp);
void mx_err_dist(int err);

#endif

