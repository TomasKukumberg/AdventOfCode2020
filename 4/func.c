#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "func.h"

bool is_empty_line(char *line, size_t len) {
     size_t empty_char_cnt = 0;
    
    for(int i = 0; i < len; i++) {
        if(isspace(line[i]) == 0) {
            break;
        } else {
            ++empty_char_cnt;
        }
        if(empty_char_cnt == len) {
            return true;
        } else {
            return false;
        }
    }
}