#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "func.h"

#define ENTRY_SIZE 7

int main(int argc, char **argv) {
    int nread;
    char *line = NULL;
    size_t length = 0;
    FILE *fp = fopen("input.txt", "r");
    size_t count = 0;
    bool entry[ENTRY_SIZE] = {false};

    while ( ( nread = getline(&line, &length, fp) ) != -1) {
        if(is_line_empty(line, strlen(line)) == false) {
            validate_line(line, entry);
        } else {
            if(is_entry_valid(entry, ENTRY_SIZE)) {
                count++;
            }
            reset_entry(entry, ENTRY_SIZE);
        }
    }
    
    if(is_entry_valid(entry, ENTRY_SIZE)) {
        count++;
    }

    printf("Number of valid entries: %d", count);
    fclose(fp);
    return 0;
}