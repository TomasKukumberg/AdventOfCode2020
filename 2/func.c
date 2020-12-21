#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

size_t count_valid_passwords() {
    FILE* fp = fopen("input.txt", "r");
    size_t nread;
    char *line = NULL;
    size_t length = 0;
    size_t valid_pass_cnt = 0;
    
    while ((nread = getline(&line, &length, fp)) != -1) {
        if(is_valid_pswd(line)) {
            ++valid_pass_cnt;
        }
    }
    fclose(fp);
    return valid_pass_cnt;
}

size_t count_valid_passwords_2() {
    FILE* fp = fopen("input.txt", "r");
    size_t nread;
    char *line = NULL;
    size_t length = 0;
    size_t valid_pass_cnt = 0;
    
    while ((nread = getline(&line, &length, fp)) != -1) {
        if(is_valid_pswd_2(line)) {
            ++valid_pass_cnt;
        }
    }
    free(line);
    fclose(fp);
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
    
    bool result = isBetween(cnt_substr_in_str, atoi(low), atoi(high));
    free(low);
    free(high);
    return result;
}

//potentially unsafe, expects from the caller to input data in the correct format showed in input.txt!
bool is_valid_pswd_2(const char *line) {
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
    bool result = has_letters_on_positions(line, constraint_letter, atoi(low), atoi(high));
    free(low); 
    free(high);
    return result;
}

bool has_letters_on_positions(const char* line, char letter, size_t pos_a, size_t pos_b) {
    const size_t offset = 1;
    if(line[pos_a - offset] == letter && line[pos_b - offset] != letter) {
        return true;
    } else if(line[pos_a - offset] != letter && line[pos_b - offset] == letter) {
        return true;
    } else {
        return false;
    }
}

bool isBetween(int val, int low, int high) {
    return val >= low && val <= high;
}