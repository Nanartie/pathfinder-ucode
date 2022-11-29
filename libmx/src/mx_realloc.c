#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
	if (size <= 0 && ptr) {
		free(ptr);
		return NULL;
	}
	void *res = NULL;
	size_t oldSize = malloc_size(ptr);
	if (size < oldSize) res = malloc(oldSize);
	else res = malloc(size);
	if (res == NULL) return NULL;
	mx_memcpy(res, ptr, oldSize);
	free(ptr);
	ptr = NULL;
	return res;

}

