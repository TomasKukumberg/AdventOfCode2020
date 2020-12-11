#include "func.h"
#include <stdlib.h>
#include <stdio.h>

int main(char** argv, int argc) {
    int* arr = malloc(sizeof(int) * 6);
    FILE *fp = fopen("numbers.txt", "r");
    int line_cnt;

    line_cnt = count_lines(fp);
    load_file(arr, fp, line_cnt);
    printf("Result: %d", get_result(arr, line_cnt, 2020));
    return 0;
}