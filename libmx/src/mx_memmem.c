#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
	if (!big || big_len == 0 || !little || little_len == 0) return NULL;

	int size = (int)big_len;
	for (int i = 0; i < size; i++) {
		if (((char*)big)[i] == *(char*)little) {
			if (mx_memcmp(&((char*)big)[i], little, little_len) == 1) {
				return (void*)&((char*)big)[i];
			}
		}
	}
	return NULL;
}

