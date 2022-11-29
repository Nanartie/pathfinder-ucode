#include "libmx.h"

char *mx_file_to_str(const char *filename) {
	int ptr = open(filename, O_RDONLY);
	
	if (ptr < 0) {
		close(ptr);
		return NULL;
	}
	int point = 0;
	char tmp;
	while(read(ptr, &tmp, sizeof(tmp)) != 0) {
		point++;
	}
	close(ptr);
	if(point <= 0)
		return NULL;
	//char *str = (char*)malloc((point + 1) * sizeof(char));
	char *str = mx_strnew(point);
	if (str == NULL) 
		return NULL;
	ptr = open(filename, O_RDONLY);
	if (ptr < 0) {
		close(ptr);
		return NULL;
	}
	read(ptr, str, point);
	close(ptr);
	str[point] = '\0';
	return str;
}

