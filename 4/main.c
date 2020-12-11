#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "func.h"

#define SIZE 7

int main(const char ** argv, int argc) {
    size_t nread;
    char *line = NULL;
    size_t length = 0;
    size_t valid_pass_cnt = 0;
    size_t empty_char_cnt = 0;
    FILE *fp = fopen("input.txt", "r");
    size_t count = 0;
    bool fields[SIZE] = {0};

    while ( ( nread = getline(&line, &length, fp) ) != -1) {
        if(is_empty(line, strlen(line))) {
            bool test = is_entry_valid();
            if(test) {
                ++count;
            }
            reset_fields(fields, SIZE);
        } else {
            validate_line(); // (strstr(sent, word) finds a substring in string
        }
    }
    
    fclose(fp);
    return 0;
}
