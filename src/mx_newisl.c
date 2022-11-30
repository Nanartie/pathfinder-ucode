#include "pathfinder.h"

t_island* mx_newisl(t_island** islnds, char* isl) {
	t_island* buff = *islnds;
	if (!buff) {
		*islnds = mx_newisl_cr(isl);
		return *islnds;		
	}
	t_island *latest;
	for (; buff != NULL; buff = buff->next) {
		if (mx_strcmp(buff->name, isl) == 0) {
			mx_strdel(&isl);
			return buff;
		}
		if (buff->next == NULL) {
			latest = buff;
		}
	}
	latest->next = mx_newisl_cr(isl);
	return latest->next;
}

