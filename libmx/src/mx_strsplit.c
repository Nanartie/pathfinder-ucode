
#include "libmx.h"

int mx_new_size(const char *s, char c) {
    int point = 0;
    while (s[point] != c && s[point]) {
        point++;
    }
    return point;
}

char **mx_strsplit(char const *s, char c) {
    if (!s)
        return NULL;

    int words = mx_count_words(s, c) + 1;
    char **arr = (char **)malloc(words * sizeof(char *));
    int size = 0;
    int i = 0;
    while ((*s) && *s != '\0') {
        if (*s != c) {
            size = mx_new_size(s, c);
            arr[i] = mx_strndup(s, size);
            s += size;
            i++;
            continue;
        }
        s++;
    }
    arr[i] = NULL;
    return arr;
}

