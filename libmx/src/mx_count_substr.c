#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
	int lenStr = mx_strlen(str);
	int lenSub = mx_strlen(sub);
	int count = 0;
	for (int i = 0; i <= lenStr - lenSub; i++) {
        	for (int j = 0; j < lenSub; j++) {
            		if (str[i + j] != sub[j]) {
                		if (j == lenSub)
                		    count++;
               			 break;
			}
		}
    	}
	return count;
}

