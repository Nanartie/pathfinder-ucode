#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	if (!str || !sub || !replace) return NULL;
	int lenS = mx_strlen(str);
	int lenSb = mx_strlen(sub);
	int lenR = mx_strlen(replace);
	if (lenS <= lenSb) return NULL;

	int count = mx_count_substr(str, sub);
	int secLen = lenS + count * (lenR - lenSb);
	char *replaced = mx_strnew(secLen);
	for (int i = 0; i < secLen; i++) {
		if(mx_strncmp((char*)str, (char*)sub, lenSb)) {
			str = str + lenSb;
			for (int j = 0; j < lenR; j++) {
				replaced[i] = replace[j];
				i++;
			}
		}
		replaced[i] = *str;
		str++;
	}
	return replaced;
}

