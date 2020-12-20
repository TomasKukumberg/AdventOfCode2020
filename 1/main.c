#include "func.h"
#include <stdlib.h>
#include <stdio.h>

int main(char** argv, int argc) {
    int* arr;
    FILE *fp = fopen("input.txt", "r");
    int line_cnt;

    line_cnt = count_lines(fp);
    load_file(&arr, fp, line_cnt);
    printf("Solution a: %d\n", get_result_a(arr, line_cnt, 2020));
    printf("Solution b: %d\n", get_result_b(arr, line_cnt, 2020));
    fclose(fp);
    free(arr);
    return 0;
}
