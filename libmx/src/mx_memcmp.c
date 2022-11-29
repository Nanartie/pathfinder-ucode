#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
	int size = (int)n;
	for (int i = 0; i < size; i++) {
		if (((char*)s1)[i] != ((char*)s2)[i]) {
			return (int)(((char*)s1)[i] - ((char*)s2)[i]);
		}
	}
	return 0;
}

