#include "libmx.h"

int mx_readline(char **lineptr, size_t buf_size, int delim, const int fd) {
	if (buf_size == 0) return -2;
	int count = 0;
	buf_size = 1;
	char *tmp = mx_strnew(buf_size);
	int bytes = 0;
	char *new = *lineptr;
	*lineptr = NULL;
	while((bytes = read(fd, tmp, buf_size)) > 0) {
		if (mx_get_char_index(tmp, delim) >= 0) {
			tmp[mx_get_char_index(tmp, delim)] = '\0';
			*lineptr = mx_strjoin(*lineptr, tmp);
			count += mx_strlen(tmp);
			free(tmp);
			free(new);
			return count;
		}
		else {
			*lineptr = mx_strjoin(*lineptr, tmp);
			count += bytes;
		}
		
	}
	if (bytes<0) return -1;
	if(bytes < (int)buf_size && bytes !=0) return count;
	free(tmp);
	if (count == 0) {
		*lineptr = new;
		if (bytes > 0) return -1;
		else return -2;
	}
	return count;
	
}

