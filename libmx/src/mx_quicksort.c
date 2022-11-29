#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
	if (arr == NULL) return -1;
	if (left >= right) return 0;
	
	int count = 0;
	int mid = (left + right)/2;
	int startL = left;
	int startR = right;
	while (left < right) {
		while ((mx_strlen(arr[right]) >= mx_strlen(arr[mid])) && (left < right)) right--;
		if (left != right) {
			arr[left] = arr[right];
			left++;
			count++;
		}
		while ((mx_strlen(arr[left]) <= mx_strlen(arr[mid])) && (left < right)) left++;
		if (left != right) {
			arr[right] = arr[left];
			right--;
			count++;
		}
	}
	if (left != mid) {
		count++;
		char *tmp = arr[left];
		arr[left] = arr[mid];
		arr[mid] = tmp;
	}
	count += mx_quicksort(arr, startL, left - 1);
	count += mx_quicksort(arr, left + 1, startR);
	
	return count;	
}


