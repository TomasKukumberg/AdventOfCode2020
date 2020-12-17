#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "func.h"

#define ENTRY_SIZE 7

int main(const char ** argv, int argc) {
    int nread;
    char *line = NULL;
    size_t length = 0;
    size_t valid_pass_cnt = 0;
    size_t empty_char_cnt = 0;
    FILE *fp = fopen("input.txt", "r");
    size_t count = 0;
    bool entry[ENTRY_SIZE] = {false};

    while ( ( nread = getline(&line, &length, fp) ) != -1) {
        if(is_empty(line, strlen(line)) == false) {
            validate_line(line, entry);
        } else {
            if(is_valid(entry, ENTRY_SIZE)) {
                count++;
            }
            reset_entry(entry, ENTRY_SIZE);
        }
    }
    
    if(is_valid(entry, ENTRY_SIZE)) {
        count++;
    }

    printf("Number of valid entries: %d", count);
    fclose(fp);
    return 0;
}
