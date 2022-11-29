#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
	if (hex == 0) return 0;
	unsigned long nbr = 0;
	for (int i = 0; hex[i] != '\0'; i++) {
		int dg;
		if (hex[i] >= '0' && hex[i] <= '9') {
			dg = hex[i] - '0';
		}
		else {
			dg = hex[i] - 'A' + 10;
		}

		if (dg == -1) return 0;
		nbr = nbr * 16;
		nbr = nbr + dg;
	}
	return nbr;
}

/*int main() {
	char *c = "FFFFFFFFFFFF";
	printf("%lu\n", mx_hex_to_nbr(c));
}*/

