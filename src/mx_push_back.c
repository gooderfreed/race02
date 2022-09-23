#include "../inc/header.h"

void mx_push_back(t_list **list, void *data) {
    t_list *t = *list;
    while (t->next != NULL) t = t->next;
    t_list *temp = mx_create_node(data);
    t->next = temp;
}

