#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>

void load_file(int**, FILE *, int);
void print_arr(int*, int);
int get_result_a(int*, int, int);
int get_result_b(int*, int, int);
size_t count_lines(FILE *);

#endif