#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
	if (pow == 0) {
		return 1;
	}
	else if (pow == 1) {
		return n;
	}
	else {
		double res = 1;
		for (unsigned int i = 0; i < pow; i++) {
			res *= n;
		}
		return res;
	}
}

