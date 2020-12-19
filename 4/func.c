#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

bool is_line_empty(char *line, size_t len) {
    if(strcmp(line, "\n") == 0) {
        return true;
    } else {
        return false;
    }
}

void reset_entry(bool *arr, size_t len) {
    for(size_t i = 0; i < len; i++) {
        arr[i] = false;
    }
}

char * parse_value(char *line, size_t *key_length) {
    const int offset = 4;
    char *tmp = calloc(50, sizeof(char));
    line += offset;
    for(char* i = line; *i != ' ' && *i != '\n'; i++) {
        tmp[*key_length] = *i;
        (*key_length)++;
    }
    return tmp;
}

bool parse_issue_year(char *line) {
    size_t value_length = 0;
    const size_t base = 10;
    char * tmp = parse_value(line, &value_length);
        
    if(value_length < 4) {
        free(tmp);
        return false;
    }
        
    char* p_end;
    long int num = strtol(tmp, &p_end, base);
    free(tmp);
        
    if((errno == LONG_MAX || errno == LONG_MIN) && num == 0) {
        return false;
    } else if(num >= 2010 && num <= 2020) {
        return true;
    } else {
        return false;
    }
}

bool parse_exp_year(char *line) {
    size_t value_length = 0;
    char * tmp = parse_value(line, &value_length);
        
    if(value_length < 4) {
        free(tmp);
        return false;
    }
        
    char* p_end;
    long int num = strtol(tmp, &p_end, 10);
    free(tmp);
        
    if((errno == LONG_MAX || errno == LONG_MIN) && num == 0) {
        return false;
    } else if(num >= 2020 && num <= 2030) {
        return true;
    } else {
        return false;
    }
}

bool parse_birth_year(char *line) {
    size_t value_length = 0;
    char * tmp = parse_value(line, &value_length);
        
    if(value_length < 4) {
        free(tmp);
        return false;
    }
        
    char* p_end;
    long int num = strtol(tmp, &p_end, 10);
    free(tmp);
        
    if((errno == LONG_MAX || errno == LONG_MIN) && num == 0) {
        return false;
    } else if(num >= 1920 && num <= 2002) {
        return true;
    } else {
        return false;
    }
}

bool parse_height(char *line) {
    const int offset = 4;
    line += offset;
    int j = 0;     
    char * tmp = calloc(50, sizeof(char));
    char *test = line; 
    
    line = strstr(line, "cm");

    if(line == NULL) {
        line = strstr(test, "in");
        if(line == NULL) {
            return false;
        }
        for(char* i = test; i != strstr(test, "in"); i++) {
            tmp[j++] = *i;
        }
        if((line - test) < 2) { 
            free(tmp);
            return false;
        }
        char* p_end;
        long int num = strtol(tmp, &p_end, 10);
            
        if((errno == LONG_MAX || errno == LONG_MIN) && num == 0) {
            free(tmp);
            return false;
        } else if(num >= 59 && num <= 76) {
            free(tmp);
            return true;
        } else {
            free(tmp);
            return false;
        }
    } else {
        for(char* i = test; i != strstr(test, "cm"); i++) {
            tmp[j++] = *i;
        }
        if((line - test) < 3) { 
            free(tmp);
            return false;
        }
        char* p_end;
        long int num = strtol(tmp, &p_end, 10);
            
        if((errno == LONG_MAX || errno == LONG_MIN) && num == 0) {
            free(tmp);
            return false;
        } else if(num >= 150 && num <= 193) {
            free(tmp);
            return true;
        } else {
            free(tmp);
            return false;
        }
    }

}

bool is_hair_color_valid(char *line) {
    for(size_t i = 0; i < strlen(line); i++) {
        switch(line[i]) {
            case '0': 
            case '1': 
            case '2': 
            case '3': 
            case '4': 
            case '5': 
            case '6': 
            case '7': 
            case '8': 
            case '9': 
            case 'a': 
            case 'b': 
            case 'c': 
            case 'd': 
            case 'e': 
            case 'f': break;
            default: return false; 
        }
    }
    return true;
}

bool is_eye_color_valid(char *line) {    
    if(strcmp(line, "amb") == 0 || strcmp(line, "blu") == 0 || strcmp(line, "brn") == 0 || strcmp(line, "gry") == 0 ||
        strcmp(line, "grn") == 0 || strcmp(line, "hzl") == 0 || strcmp(line, "oth") == 0 ) {
           return true;
    } else {
        return false;
    } 
}

bool parse_hair_color(char *line) {
    const int offset = 4;
    line += offset;
    if(*line != '#') {
        return false;
    } 
    line -= offset;

    size_t value_length = 0;
    char * tmp = parse_value(++line, &value_length);

    if(value_length != 6) { 
        free(tmp);
        return false;
    }

    bool result = is_hair_color_valid(tmp);
    free(tmp);
    return result;
}

bool parse_eye_color(char *line) {
    size_t value_length = 0;
    char * tmp = parse_value(line, &value_length);

    if(value_length != 3) { 
        free(tmp);
        return false;
    }

    bool result = is_eye_color_valid(tmp);
    free(tmp);
    return result;
}

bool is_valid_pid_num(char letter) {
    switch(letter) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': return true;
        default: return false;
    }
}

bool parse_pid(char *line) {
    size_t value_length = 0;
    char * tmp = parse_value(line, &value_length);
        
    if(value_length != 9) {
        free(tmp);
        return false;
    }

    for(size_t i = 0; i < strlen(tmp); i++) {
        if(is_valid_pid_num(tmp[i]) == false) {
            return false;
        }
    }
    return true;
}

void validate_line(char *line, bool *entry) {
    char *has_bday = strstr(line, "byr");

    if(has_bday != NULL) {
        bool ret = parse_birth_year(has_bday);
    
        if(ret == true) {
            entry[0] = true;
        } else {
            entry[0] = false;
        }
    }

    char *has_issue_year = strstr(line, "iyr");

    if(has_issue_year != NULL) {
        bool ret = parse_issue_year(has_issue_year);
    
        if(ret == true) {
            entry[1] = true;
        } else {
            entry[1] = false;
        }
    }

    char *has_exp_year = strstr(line, "eyr");

    if(has_exp_year != NULL) {
        bool ret = parse_exp_year(has_exp_year);

        if(ret == true) {
            entry[2] = true;
        } else {
            entry[2] = false;
        }
    }

    char *has_height = strstr(line, "hgt");

    if(has_height != NULL) {
        bool ret = parse_height(has_height);

        if(ret == true) {
            entry[3] = true;
        } else {
            entry[3] = false;
        }
    }

    char *has_hair_color = strstr(line, "hcl");

    if(has_hair_color != NULL) {
        bool ret = parse_hair_color(has_hair_color);

        if(ret == true) {
            entry[4] = true;
        } else {
            entry[4] = false;
        }
    }

    char *has_eye_color = strstr(line, "ecl");

    if(has_eye_color != NULL) {
        bool ret = parse_eye_color(has_eye_color);

        if(ret == true) {
            entry[5] = true;
        } else {
            entry[5] = false;
        }
    }

    char *has_pid = strstr(line, "pid");

    if(has_pid != NULL) {
        bool ret = parse_pid(has_pid);

        if(ret == true) {
            entry[6] = true;
        } else {
            entry[6] = false;
        }
    }
    
}

bool is_entry_valid(bool *entry, size_t len) {
    for(size_t i = 0; i < len; i++) {
        if(entry[i] == false) {
            return false;
        }
    }
    return true;
}