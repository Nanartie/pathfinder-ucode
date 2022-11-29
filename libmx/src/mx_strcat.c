#include "libmx.h"

char *mx_strcat(char *s1, const char *s2) {
	char *point = s1 + mx_strlen(s1);
	//for (int i = 0; s1[i] != '\0'; i++) {
	//	point[i] = s1[i];
	//}
	while (*s2 != '\0') {
		*point++ = *s2++;
	}
	*point = '\0';
	return s1;
}

