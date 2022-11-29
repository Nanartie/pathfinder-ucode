#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
	int size = (int)n;
	for (int i = 0; i < size; i++) {
		if (((char*)src)[i] == (char)c) {
			((char*)dst)[i] = ((char*)src)[i];
			return (void*)&(((char*)dst)[i+1]);
		}
		else {
			((char*)dst)[i] = ((char*)src)[i];
		}
	}
	return NULL;
}

