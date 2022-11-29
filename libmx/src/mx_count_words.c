#include "libmx.h"

int mx_count_words(const char *str, char delimiter) {
	if (str == NULL) return -1;
	int count = 0;
	int point = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == delimiter) {
			point = 0;
		}
		else if (point == 0) {
			count++;
			point = 1;
		}
	}
	return count;
}

