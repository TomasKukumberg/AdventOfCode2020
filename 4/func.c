#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool is_empty(char *line, size_t len) {
    if(strcmp(line, "\n") == 0) {
        return true;
    } else {
        return false;
    }
}

void reset_fields(bool *arr, size_t len) {
    for(size_t i = 0; i < len; i++) {
        arr[i] = false;
    }
}