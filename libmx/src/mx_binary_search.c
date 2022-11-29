#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
	int low = 0;
	int high =  size - 1;
	int mid = 0;
	while (low <= high) {
		(*count)++;
		mid = (low + high) / 2;
		if (mx_strcmp(s, arr[mid]) < 0) {
			//	(*count)++;
				high = mid - 1;
		}
		else if (mx_strcmp(s, arr[mid]) > 0) {
			//	(*count)++;
				low = mid + 1;
		}
		else {
			return mid;
		}
	}
	(*count) = 0;
	return -1;
}

/*int main() {
	char *arr[] = {"222", "Abcd", "aBc", "ab", "az", "z"};
	int count = 0;
	printf("%i, %i", mx_binary_search(arr, 6, "aBz", &count), count);
}*/


