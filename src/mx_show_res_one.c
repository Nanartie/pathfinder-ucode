#include "pathfinder.h"

static t_way *this_way_for(t_way *buf) {
	t_way *temp = buf;
	while (temp->next) {
		temp = temp->next;
	}
	return temp;
}


static void show_ways(t_allways *buf) {
	t_way *wayFor = this_way_for(buf->road);
	mx_printstr("Path: ");
	mx_printstr(buf->road->wayFor->name);
	mx_printstr(" -> ");
	mx_printstr(wayFor->wayFor->name);
	mx_printchar('\n');
}

static void show_road(t_way *way) {
	t_way *buf = way;
	mx_printstr("Route: ");
	for(; buf != NULL; buf = buf->next) {
		if (buf->next != NULL) {
			mx_printstr(buf->wayFor->name);
			mx_printstr(" -> ");
		}
		else {
			mx_printstr(buf->wayFor->name);
		}
	}
	mx_printchar('\n');
}

static void show_length(t_way *way) {
	t_way *buf = way->next;
	int length = 0;
	mx_printstr("Distance: ");
	if (!buf->next) {
		mx_printint(buf->length);
	}
	else {
		for(; buf != NULL; buf = buf->next) {
			length += buf->length;
			if (!buf->next) {
				mx_printint(buf->length);
				mx_printstr(" = ");
				mx_printint(length);
			}
			else {
				mx_printint(buf->length);
				mx_printstr(" + ");
			}
		}
	}
	mx_printchar('\n');
}

void mx_show_res_one(t_allways *temp) {
	t_allways *buf = temp;
	for (; buf != NULL; buf = buf->next) {
		if (buf->res == true) {
			for (int i = 0; i < 40; i++) {
				mx_printchar('=');
			}
			mx_printchar('\n');
			show_ways(buf);
			show_road(buf->road);
			show_length(buf->road);
			for (int i = 0; i < 40; i++) {
				mx_printchar('=');
			}
			mx_printchar('\n');
		}						
	}
}
