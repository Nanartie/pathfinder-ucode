#include "libmx.h"

void mx_strdel(char **str) {
	free(*str);
	*str = NULL;
}

/*int main() {
	char *str = malloc(10);
	strcpy(str, "Words\n");
	printf("%s", str);
	mx_strdel(&str);
	printf("%s", str);
}*/

