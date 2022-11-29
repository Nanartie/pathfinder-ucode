#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
	size_t size = mx_strlen(s1);
	char *str = NULL;
	//int sizeN = (int)n;
	if (n < size) 
		size = n;
	str = mx_strnew(size);
	mx_strncpy(str, s1, size);
	return str;
	
}

