#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct unit_t {
    int index;
    char symbol;
    int prev;
    int size;
    bool visited;
}              unit;

typedef struct s_list {
    void *data;
    struct s_list *next;
}              t_list;

int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
int mx_strlen(const char *s);
void mx_printerr(const char *s);
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_printchar(char c);

int mx_get_size_row(char *name);
int mx_get_size_column(char *name);
void mx_write_list(unit **list, int column, int row);
unit **mx_create_list(char *name, int column, int row);
void mx_print_path(unit **list, int end, int dist);


void mx_pop_front(t_list **list);
t_list *mx_create_node(void *data);
void mx_push_back(t_list **list, void *data);
unit *mx_get_front(t_list **list);
void mx_pop_front(t_list **list);
void mx_isright(unit **list, t_list *queue, unit *t, int arg);
void mx_search_path(unit **list, int size_row, int size_list, int start, int end);
void mx_check_map(char *name);

int main (int argc, char *argv[]);


#endif
