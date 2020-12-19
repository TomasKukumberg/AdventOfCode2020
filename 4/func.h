#ifndef FUNC_H
#define FUNC_H

bool is_line_empty(char *, size_t);
void reset_entry(bool *, size_t);
void validate_line(char *, bool *);
bool is_entry_valid(bool *, size_t);
bool is_hair_color_valid(char *);
bool is_eye_color_valid(char *);
bool parse_birth_year(char *);
bool parse_issue_year(char *);
bool parse_hair_color(char *);
bool parse_eye_color(char *);
char * parse_value(char *);
#endif