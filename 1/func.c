#include <stdio.h>
#include <stdlib.h>
#include "func.h"

size_t count_lines(FILE* fp){
    size_t nread;
    char *line = NULL;
    size_t length = 0;
    size_t line_cnt = 0;
     
    while ((nread = getline(&line, &length, fp)) != -1) {
        ++line_cnt;
    }
    rewind(fp);
    return line_cnt;
}

void load_file(int** arr, FILE *fp, int len) {
    size_t nread;
    char *line = NULL;
    size_t length = 0;
    size_t i = 0;
    *arr = malloc(sizeof(int) * len);

    while ((nread = getline(&line, &length, fp)) != -1) {
        (*arr)[i++] = atoi(line); //TODO replace with strtonum(const char *nptr, long long minval, long long maxval,const char **errstr);
    }
}

void print_arr(int* arr, int len) {
    for(size_t i = 0; i < len; i++) {
        printf("%d: %d\n", i, arr[i]);
    }
}

int get_result(int* arr, int len, int val) {
    for(size_t i = 0; i < len; i++) {
        for(size_t j = i; j < len; j++) {
            if(arr[i] + arr[j] == val) {
                return arr[i] * arr[j];
            }
        }
    }
}
