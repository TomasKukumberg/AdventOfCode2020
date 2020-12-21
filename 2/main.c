#include <stdio.h>
#include "func.h"
#include <string.h>

int main(char** argv, int argc) {
    
    printf("Number of valid passwords: %d\n", count_valid_passwords());
    printf("Number of valid passwords in 2nd job: %d\n", count_valid_passwords_2());
    
    return 0;
}