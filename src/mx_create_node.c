#include "../inc/header.h"

t_list *mx_create_node(void *data) {
    t_list *temp = (t_list*)malloc(sizeof(t_list));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

