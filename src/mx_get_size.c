#include "../inc/header.h"

int mx_get_size_row(char *name) {
    int t = open(name, O_RDONLY);
    int size = 0;
    char buff;

    while (read(t, &buff, 1) == 1) {
        if (buff == '\n') break;
        if (buff != ',') size++;
    }
    return size;
}

int mx_get_size_column(char *name) {
    int t = open(name, O_RDONLY);
    int nl = 0;
    char buff;

    while (read(t, &buff, 1) == 1) {
        if (buff == '\n') nl++;
    }
    return nl;
}

