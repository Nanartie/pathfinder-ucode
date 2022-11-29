#include "libmx.h"

char *mx_strtrim(const char *str) {
	if (str == NULL) return NULL;
	int num = 0;
	int ind = 0;
	for (ind = 0; mx_isspace(str[ind]); ind++) {
		num++;
	}
	for (int i = mx_strlen(str) - 1; mx_isspace(str[i]); i--) {
		num++;
	}
	char *s1 = mx_strnew(mx_strlen(str) - num);
	if (s1 == NULL) return NULL;
	mx_strncpy(s1, str + ind, mx_strlen(str) - num);
	return s1;
}

/*int main() {
	char str[] = "\f My name... is Neo \t\n ";
	printf("%s", mx_strtrim(str));
}*/



