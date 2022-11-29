#include "libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
	if (s1 == NULL && s2 == NULL) return NULL;
	else if (s1 == NULL) {
		char *str =  mx_strdup(s2);
		if (str == NULL) return NULL;
		return str;
	}
	else if (s2 == NULL) {
		char *str = mx_strdup(s1);
		if (str == NULL) return NULL;
		return str;
	}
	else {
		char *str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
		if (str == NULL) return NULL;
		else {
			str = mx_strdup(mx_strcat((char*)s1, (char*)s2));
			return str;
		}
	}
}

/*int main() {
	char str1[] = "this";
	char str2[] = "dodge ";
	//char str3[] = "\0";
	printf("%s\n", mx_strjoin(str2, str1));
	//printf("%s\n", mx_strjoin(str1, str3));
	//printf("%s\n", mx_strjoin(str3, str3));
}*/

