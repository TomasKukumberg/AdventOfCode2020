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
        if(is_valid_pswd(line)) {
            ++valid_pass_cnt;
        }
    }

    return valid_pass_cnt;
}

//potentially unsafe, expects from the caller to input data in the correct format showed in input.txt!
bool is_valid_pswd(const char *line) {
    char* low = calloc(2, sizeof(char));
    char* high = calloc(2, sizeof(char));
    size_t cnt_substr_in_str = 0;
    size_t index = 0;

    for(; *line != '-'; line++) {
        low[index++] = *line;
    }
    
    line++;
    
    for(index = 0; *line != ' '; line++) {
        high[index++] = *line;
    }
    
    line++;
    char constraint_letter = *line;
    line += 3;

    for(; *line != ' ' && *line != '\n'; line++) {
        if(*line == constraint_letter) {
            cnt_substr_in_str++;
        }
    }
    
    return isBetween(cnt_substr_in_str, atoi(low), atoi(high));
}

bool isBetween(int val, int low, int high) {
    return val >= low && val <= high;
}