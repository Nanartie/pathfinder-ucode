#include "libmx.h"

int mx_sqrt(int x) {
	if (x < 0) {
		return 0;
	}
	else {
		int res = 0;
		for (int i = 2; i < x; i++) {
			if (x / i == i) {
				res = i;
				break;
			}
			else {
				res = 0;
			}
		}
		if (res != 0) {
			return res;
		}
		else {
			return 0;
		}
	}
}

