#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
	unsigned char *new = malloc(len);
	new = mx_memcpy(new, src, len);
	dst = mx_memcpy(dst, new, len);
	free(new);
	new = NULL;
	return dst;
}

