#include "libmx.h"

char *mx_itoa(int number) {
	int power = 1;
	int j = number;
	int point = 0;
	if (number < 0) power++;
	for (; j >= 10 || j <= -10; j /= 10) {
		power++;
	}
	char *res = mx_strnew(power);
	if (number < 0) {
		res[0] = '-';
		point = 1;
	}
	for (int i = power; i > point; i--) {
		int resN = number % 10;
		if (resN < 0) resN *= -1;
		res[i-1] = '0' + resN;
		number /= 10;
	}
	//*res = '\0';
	return res;
}
/*#include <stdio.h>
int main() {
	int number = 1735468;
	char *temp = mx_itoa(number);
	printf("%s\n", temp);
}*/

