#include "../inc/header.h"

void mx_print_path(unit **list, int end, int dist) {
    if (list[end]->prev != -1) {
        int len = 0;
        unit *t = list[end];
        while (t->prev != -1) {
            if (t->symbol == 'D') t->symbol = 'X';
            else t->symbol = '*';
            len++;
            t = list[t->prev];
        }
        if (t->symbol == 'D') t->symbol = 'X';
        else t->symbol = '*';
        mx_printstr("dist=");
        mx_printint(dist);
        mx_printstr("\n");
        mx_printstr("exit=");
        mx_printint(len);
        mx_printstr("\n");
        return;
    }
    mx_printerr("route not found\n");
    exit(0);
}

