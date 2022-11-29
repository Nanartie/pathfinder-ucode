#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
	if (delim == NULL || arr == NULL) return;
	for (int i = 0; arr[i] != NULL; i++) {
		mx_printstr(arr[i]);
		mx_printstr(delim);
	}
}

/*int main() {
	char *arr[] = {"First", "Second", NULL};
	char delim[] = " num ";
	mx_print_strarr(arr, delim);
}*/

