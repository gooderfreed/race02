#include "../inc/header.h"

void mx_write_list(unit **list, int column, int row) {
    int file = open("path.txt", O_CREAT | O_RDWR, 00660);
    for (int i = 0; i < row*column; i++) {
        if (i != 0 && i%row == 0) write(file, "\n", 1);
        write(file, &list[i]->symbol, 1);
    }
    write(file, "\n", 1);
    close(file);
}

