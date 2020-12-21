#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdbool.h>

size_t count_valid_passwords();
size_t count_valid_passwords_2();
bool is_valid_pswd(const char *);
bool is_valid_pswd_2(const char *);
bool isBetween(int, int, int);
bool has_letters_on_positions(const char *, char, size_t, size_t);

#endif