#include "libmx.h"

char *mx_strdup(const char *str) {
	int size = mx_strlen(str);
	char *s1;
	s1 = mx_strnew(size);
	if (s1 == NULL) {
		return NULL;
	}
	else {
		mx_strcpy(s1, str);
		return s1;
	}
}

/*int main() {
	char *str = "wordswords";
	char *s1 = mx_strdup(str);
	printf("%s\n", s1);
}*/

