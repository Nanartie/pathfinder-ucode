#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
	for (int i = 0; i < (int)len; i++) {
		((char*)b)[i] = (char)c;
	}
	return b;
}

