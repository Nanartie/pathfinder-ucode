#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
	if (str == NULL || sub == NULL) return -2;
	int ind = 0;
	int len = mx_strlen(sub);
	while (str[ind] != '\0') {
		if (str[ind] == *sub) {
			if (mx_strncmp(str, sub, len) == 0) return ind;
		}
		ind++;
	}
	return -1;
}

