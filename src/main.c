#include "../inc/header.h"

int main (int argc, char *argv[]) {
    if (argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        exit(0);
    }

    mx_check_map(argv[1]);
    int row = mx_get_size_row(argv[1]);
    int column = mx_get_size_column(argv[1]);
    unit **list = mx_create_list(argv[1], column, row);

    int x1 = mx_atoi(argv[2]);
    int y1 = mx_atoi(argv[3]);
    int x2 = mx_atoi(argv[4]);
    int y2 = mx_atoi(argv[5]);
    int num1 = y1 * row + x1;
    int num2 = y2 * row + x2;

    if (x1 > row || x2 > row 
        || x1 < 0 || x2 < 0
        || y1 > column || y2 > column
        || y1 < 0 || y2 < 0) {
        mx_printerr("points are out of map range\n");
        exit(0);
    }

    if (list[num1]->symbol == '#') {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(0);
    }

    if (list[num2]->symbol == '#') {
        mx_printerr("exit point cannot be an obstacle\n");
        exit(0);
    }

    mx_search_path(list, row, row*column, num1, num2);
    mx_write_list(list, column, row);

    return 0;
}

