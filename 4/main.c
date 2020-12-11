#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "func.h"

int main(const char ** argv, int argc) {
    size_t nread;
    char *line = NULL;
    size_t length = 0;
    size_t valid_pass_cnt = 0;
    size_t empty_char_cnt = 0;
    FILE *fp = fopen("input.txt", "r");
    
    while ( ( nread = getline(&line, &length, fp) ) != -1) {
        size_t line_size = strlen(line);
        bool empty_line = is_empty_line(line, line_size);
        printf("is empty line: %d\n", empty_line);
    }
    
    fclose(fp);
    return 0;
}
