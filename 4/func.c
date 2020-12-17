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

void reset_entry(bool *arr, size_t len) {
    for(size_t i = 0; i < len; i++) {
        arr[i] = false;
    }
}

void validate_line(char* line, bool* entry) {
    size_t line_size = strlen(line);
    if(strstr(line, "byr") != NULL) {
        entry[0] = true;
    }
    if(strstr(line, "iyr") != NULL) {
        entry[1] = true;
    } 
    if(strstr(line, "eyr") != NULL) {
        entry[2] = true;
    } 
    if(strstr(line, "hgt") != NULL) {
        entry[3] = true;
    }
    if(strstr(line, "hcl") != NULL) {
        entry[4] = true;
    } 
    if(strstr(line, "ecl") != NULL) {
        entry[5] = true;
    } 
    if(strstr(line, "pid") != NULL) {
        entry[6] = true;
    }
}

bool is_valid(bool* entry, size_t len) {
    for(size_t i = 0; i < len; i++) {
        if(entry[i] == false) {
            return false;
        }
    }
    return true;
}