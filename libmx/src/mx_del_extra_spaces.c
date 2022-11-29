#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
	if(str == NULL) return NULL;
	char *s1 = mx_strtrim(str);
	//int count = 0;
	int len = mx_strlen(s1);
	char *res = mx_strnew(len);
	if (res == NULL) return NULL;
	int i = 0;
	int j = 0;
	for (; s1[i] != '\0'; i++) {
		if (mx_isspace(s1[i])) {
			for (res[j++] = ' '; mx_isspace(s1[i]); i++);
		}
		res[j++] = s1[i];
	}
	
	int lenR = mx_strlen(res);
	char *end = mx_strnew(lenR);
	if (end == NULL) return NULL;
	mx_strcpy(end, res);
	mx_strdel(&s1);
	mx_strdel(&res);
	return end;
}

/*int main() {
	char name[] = "\f My name...	is \r Neo \t\n";
	printf("%s", mx_del_extra_whitespaces(name));
}*/
