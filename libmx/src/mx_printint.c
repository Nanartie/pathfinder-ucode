#include "libmx.h"


void mx_printint(int n) 
{
    if (n < 0){
        mx_printchar('-');
        n *= -1;
    }
    if (n == 0) {
	mx_printchar(48);
    }
    if (n == -2147483648) {
	write(1, "-2147483648", 11);
    }
    if (n == 2147483647) {
	write(1, "2147483647", 10);
    }

    if (n > 9) {
    	mx_printint(n / 10);
    }
    mx_printchar(n % 10 + 48);
}


