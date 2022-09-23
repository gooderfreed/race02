#include "../inc/header.h"

unit *mx_get_front(t_list **list) {
    unit *res =(*list)->data;
    return res;
}

void mx_pop_front(t_list **list) {
    t_list *temp = (*list)->next;
    free((*list));
    *list = temp;
}

