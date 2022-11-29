#include "pathfinder.h"

void mx_new_way(t_way **ways, t_island *second, int length) {
	t_way *buf = *ways;
        if(!buf) {
                *ways = malloc(sizeof(t_way));
                (*ways)->wayFor = second;
                (*ways)->next = NULL;
                (*ways)->length = length;
                free(buf);
                return;
        }
        t_way *latest;
	for (; buf != NULL; buf = buf->next) {
                if (second == buf->wayFor) {
                	mx_printerr("error: duplicate bridges\n");
			exit(0);
                }
                if (buf->next == NULL) 
                	latest = buf;
        }
        latest->next = malloc(sizeof(t_way));
        latest->next->wayFor = second;
        latest->next->next = NULL;
        latest->next->length = length;
}

