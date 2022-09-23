#include "../inc/header.h"

void mx_isright(unit **list, t_list *queue, unit *t, int arg) {
    if (list[t->index+arg]->visited != true)
        list[t->index+arg]->prev = t->index;
    mx_push_back(&queue, list[t->index+arg]);
}

void mx_search_path(unit **list, int size_row, int size_list, int start, int end) {
    t_list *queue = mx_create_node(list[start]);
    t_list *qdistant = mx_create_node(list[start]);
    int max_dist = 0;

    while(queue) {
        unit *t = mx_get_front(&queue);

        if (t->symbol != '#') {
            if (t->visited != true) {
                if (t->prev != -1) {
                    t->size = list[t->prev]->size + 1;
                    if (t->size >= max_dist) {
                        max_dist = t->size;
                        mx_push_back(&qdistant, &t->index);
                    }
                }
                t->visited = true;
                if (t->index/size_row == (t->index+1)/size_row) {
                    mx_isright(list, queue, t, 1);
                }
                if (t->index + size_row < size_list) {
                    mx_isright(list, queue, t, size_row);
                }
                if (t->index / size_row == (t->index - 1)/size_row) {
                    mx_isright(list, queue, t, -1);
                }
                if (t->index-size_row >= 0) {
                    mx_isright(list, queue, t, -size_row);
                }
            }
        }
        mx_pop_front(&queue);
    }
    while (qdistant != NULL) {
        if (list[*(int *)qdistant->data]->size == max_dist)
            list[*(int *)qdistant->data]->symbol = 'D';
        qdistant = qdistant->next;
    }
    while (qdistant) mx_pop_front(&qdistant);
    mx_print_path(list, end, max_dist);
}

