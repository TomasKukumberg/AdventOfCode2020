#include <stdio.h>
#include "func.h"

int main(char** argv, int argc) {
    FILE* fp = fopen("input.txt", "r");

    int count = count_valid_passwords(fp);
    printf("Number of valid passwords: %d\n", count);

    fclose(fp);
    return 0;
}

//TODO FIX PARSING 