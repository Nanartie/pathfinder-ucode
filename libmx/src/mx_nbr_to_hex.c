#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	if (!nbr) return NULL;
	long tmp;
	int ind = 0;
	int cn = 1;
	tmp = nbr;
	for (unsigned long i = tmp; i >= 16; i /= 16) {
		cn++;
	}
	char *hex = mx_strnew(cn);
	tmp = nbr;
	cn = 0;
	while (tmp != 0) {
		if (tmp % 16 < 10) hex[ind++] = 48 + tmp % 16;
		else hex[ind++] = 87 + tmp % 16;
		cn++;
		tmp = tmp/16;
	}
	char *hexret = mx_strnew(cn);
	for (int i = 0, t = cn - 1; i < cn; i++, t--) {
		hexret[i] = hex[t];
	}
	return hexret;
}

