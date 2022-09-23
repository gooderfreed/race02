#include "../inc/header.h"

bool mx_isspace(char c) {
    if (c == '\040' || (c >= '\011' && c <= '\015')) {
        return 1;
    }
    else {
        return 0;
    }
}
