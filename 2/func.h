#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdbool.h>

size_t count_valid_passwords(FILE *);
bool is_valid_format(const char *);
bool isValidPass(const char *);
bool isBetween(int, int, int);
bool is_valid_pass(const char *line);

#endif