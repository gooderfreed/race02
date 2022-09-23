#include "../inc/header.h"

unit **mx_create_list(char *name, int column, int row) {
    unit **temp = (unit**)malloc(sizeof(unit)*(column*row));
    int t = open(name, O_RDONLY);
    char buff;
    int i = -1;

    while (read(t, &buff, 1) == 1) {
        if (buff != '\n' && buff != ',') {
            i++;
            unit *tmp = (unit*)malloc(sizeof(unit));
            tmp->index = i;
            tmp->prev = -1;
            tmp->size = 0;
            tmp->symbol = buff;
            tmp->visited = false;
            temp[i] = tmp;
        }
    }
    return temp;
}

