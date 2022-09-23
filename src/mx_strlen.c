#include "../inc/header.h"

int mx_strlen(const char *s) {
    const char *start = s;

    while (*s != '\0') {
        s++;
    }

    return s - start;
}
