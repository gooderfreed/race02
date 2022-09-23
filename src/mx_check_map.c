#include "../inc/header.h"

void mx_check_map(char *name) {
    int file1 = open(name, O_RDONLY);
    int file = open(name, O_RDONLY);
    char buff1;
    char buff;
    if (file < 0 || read(file1, &buff1, 1) == 0) {
        mx_printerr("map does not exist\n");
        exit(0);
    }
    int row_size = mx_get_size_row(name);
    int temp_size = 0;

    while (read(file, &buff, 1)) {
        if (buff != ',' && buff != '.' && buff != '#' && buff != '\n') {
            mx_printerr("map error\n");
            exit(0);
        }
        else {
            if (buff == '\n') {
                if (row_size != temp_size && row_size != 0) {
                    mx_printerr("map error\n");
                    exit(0);
                }
                temp_size = 0;
            }
            else {
                if (buff != ',') temp_size++;
            } 
        }
    }
}

