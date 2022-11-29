#include "libmx.h"

char *mx_strchr(const char *s, int c) {
	if (*s == '\n') {
		return NULL;
	}
	char *s1 = (char*)s;
	while (*s1) {
		if (*s1 == c) {
			return s1;
		}
		s1++;
	}
	return NULL;

}

