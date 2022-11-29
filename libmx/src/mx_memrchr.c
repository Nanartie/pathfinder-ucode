#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
	if (!s || n <= 0) return NULL;
	int size = (int)n;
	for (int i = size; i > 0; i--) {
		if (((char*)s)[i] == (char)c) {
			return (void*)&((char*)s)[i];
		}
	}
	return NULL;
}

