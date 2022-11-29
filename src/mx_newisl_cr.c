#include "pathfinder.h"

t_island* mx_newisl_cr(char* isl) {
	t_island *newIs = malloc(sizeof(t_island));
	newIs->name = isl;
	newIs->ways = NULL;
	newIs->next = NULL;
	return newIs;
}

