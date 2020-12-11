#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

size_t count_valid_passwords(FILE *fp) {
    size_t nread;
    char *line = NULL;
    size_t length = 0;
    size_t valid_pass_cnt = 0;
    
    while ((nread = getline(&line, &length, fp)) != -1) {
        if(is_valid_format(line) && is_valid_pass(line)) {
            ++valid_pass_cnt;
        }
    }

    return valid_pass_cnt;
}

bool is_valid_format(const char *line) {
    int valid_indices = isdigit(line[0]) && isdigit(line[2]);
    int valid_dash = line[1] == '-';
    int valid_spaces = isspace(line[3]);
    int valid_letter = isalpha(line[4]);
    
    return valid_indices && valid_dash && valid_spaces && valid_letter && strlen(line) > 6;
}

bool isBetween(int val, int low, int high) {
    return val >= low && val <= high;
}

bool is_valid_pass(const char *line) {
    size_t line_size = strlen(line);
    char constraint_letter = line[4];
    size_t count = 0;
    int low = atoi(&line[0]);
    int high = atoi(&line[2]);
    
    if(line_size < 8) {
        return false;
    }

    for(int i = 7; i < line_size; i++) {
        if(line[i] == constraint_letter) {
            ++count;
        }
    }

    if(isBetween(count, low, high)) {
        return true;
    } else {
        return false;
    }
}