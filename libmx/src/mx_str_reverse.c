#include "libmx.h"

void mx_str_reverse(char *s) {
	int length = mx_strlen(s);
	char *begin = s;
	char *end = s;

	for (int i = 0; i < length - 1; i++) {
	       end++;
	}
	for (int i = 0; i < length / 2; i++) {
		mx_swap_char(begin, end);
		begin++;
		end--;
	}
}

