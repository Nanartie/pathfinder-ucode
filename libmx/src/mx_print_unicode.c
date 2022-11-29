#include "libmx.h"

void mx_print_unicode(wchar_t c) {
	if (c < 0x80) {
		char prnt[1];
		prnt[0] = (c >> 0 & 0x7F) | 0x00;
		write(1, prnt, 1);
	}
	else if (c < 0x0800) {
		char prnt[2];
		prnt[0] = (c >> 6 & 0x1F) | 0xC0;
		prnt[1] = (c >> 0 & 0x3F) | 0x80;
		write(1, prnt, 2);
	}
	else if (c < 0x010000) {
		char prnt[3];
		prnt[0] = (c >> 12 & 0x0F) | 0xE0;
		prnt[1] = (c >> 6 & 0x3F) | 0x80;
                prnt[2] = (c >> 0 & 0x3F) | 0x80;
                write(1, prnt, 3);
	}
	else if (c < 0x110000) {
		char prnt[4];
		prnt[0] = (c >> 18 & 0x07) | 0xF0;
		prnt[1] = (c >> 12 & 0x3F) | 0x80;
                prnt[2] = (c >> 6 & 0x3F) | 0x80;
                prnt[3] = (c >> 0 & 0x3F) | 0x80;
		write(1, prnt, 4);
	}

}

