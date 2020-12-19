#ifndef FUNC_H
#define FUNC_H

bool is_empty(char *, size_t);
void reset_entry(bool *, size_t);
void validate_line(char *, bool *);
bool is_valid(bool *, size_t);
void move_char_ptr(char **, size_t);
bool parse_birth_year(char *);
bool parse_issue_year(char *);
bool parse_hair_color(char *);
bool parse_eye_color(char *);
bool is_valid_hair_color(char *);
bool is_valid_eye_color(char *);
#endif