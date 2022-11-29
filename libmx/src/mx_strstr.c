#include "libmx.h"

char *mx_strstr(const char *s1, const char *s2) {
	int length2 = mx_strlen(s2) - 1;
	for (int i = 0; s1[i + length2] != '\0'; i ++) {
	        if (mx_strncmp(&s1[i], s2, length2) == 0) {
	        	return (char *)&s1[i];
	        }
	    }
	return NULL;
}
		
