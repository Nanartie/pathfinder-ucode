#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
	if (str == NULL) return -2;
	int ind = 0;
	for(; str[ind] != '\0'; ind++) {
		if (str[ind] == c) return ind;
	}
	return -1;
}

