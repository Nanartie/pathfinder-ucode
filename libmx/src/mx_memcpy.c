#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
	int size = 0;
	int end = (int)n;
	while(size < end) {
		((char*)dst)[size] = ((char*)src)[size];
		size++;
	}
	return dst;
}

