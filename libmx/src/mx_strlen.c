#include "libmx.h"

int mx_strlen(const char *s) {
	int length = 0;
	while (s[length] != '\0') {
		length += 1;
	}

	return length;
}

