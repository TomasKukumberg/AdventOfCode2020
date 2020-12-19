#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

bool is_empty(char *line, size_t len) {
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

void move_char_ptr(char **str, size_t offset) {
    *str = *str + offset;
}

bool parse_issue_year(char *cp) {
    //TODO make a parse_4_digit_num method 
    const int offset = 4;
    char * tmp = calloc(50, sizeof(char));
    
    cp += offset;
    int j = 0;     
        
    for(char* i = cp; *i != ' ' && *i != '\n'; i++) {
        tmp[j++] = *i;
    }
        
    if(j < 4) {
        free(tmp);
        return false;
    }
        
    char* p_end;
    long int num = strtol(tmp, &p_end, 10);
    free(tmp);
        
    if((errno == LONG_MAX || errno == LONG_MIN) && num == 0) {
        return false;
    } else if(num >= 2010 && num <= 2020) {
        return true;
    } else {
        return false;
    }

}

bool parse_exp_year(char *cp) {
    const int offset = 4;
    char * tmp = calloc(50, sizeof(char));
    
    cp += offset;
    int j = 0;     
        
    for(char* i = cp; *i != ' ' && *i != '\n'; i++) {
        tmp[j++] = *i;
    }
        
    if(j < 4) {
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

bool parse_birth_year(char *cp) {
    //TODO make a parse_4_digit_num method 
    const int offset = 4;
    char * tmp = calloc(50, sizeof(char)); //TODO USE STRDUP, STRNDUP
    
    cp += offset;
    int j = 0;     
        
    for(char* i = cp; *i != ' ' && *i != '\n'; i++) {
        tmp[j++] = *i;
    }
        
    if(j < 4) {
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

//HEIGHT IS PROB WRONG, ALWAYS RETURNS FALSE
bool parse_height(char *line) {
    const int offset = 4;
    line += offset;
    int j = 0;     
    char * tmp = calloc(50, sizeof(char));
    char *test = line; 
    printf("yo: %s\n", test);
    
    line = strstr(line, "cm");

    if(line == NULL) {
        printf("didnt find cm!\n");
        line = strstr(test, "in");
        if(line == NULL) {
            printf("didnt find inch as well!\n");
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
        printf("found cm!\n");
        printf("%s\n", line);
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

bool is_valid_hair_color(char *line) {
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

bool is_valid_eye_color(char *line) {    
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
    printf("current: %c\n", *line);
    if(*line != '#') {
        return false;
    } 
    line++;
    int j = 0;
    size_t hair_color_length = 0;     
    char * tmp = calloc(offset, sizeof(char));
        
    for(char* i = line; *i != ' ' && *i != '\n'; i++) {
        tmp[j++] = *i;
        hair_color_length++;
    }

    printf("len: %d\n", hair_color_length);

    if(hair_color_length != 6) { 
        free(tmp);
        return false;
    }

    printf("hair color is: %s\n", tmp);

    bool result = is_valid_hair_color(tmp);
    free(tmp);
    return result;
}

bool parse_eye_color(char *line) {
    const int offset = 4;
    line += offset;
    int j = 0;
    size_t eye_color_length = 0;     
    char * tmp = calloc(offset, sizeof(char)); //TODO FIX ALLOCATION
        
    for(char* i = line; *i != ' ' && *i != '\n'; i++) {  
        tmp[j++] = *i;  
        eye_color_length++;
    }


    if(eye_color_length != 3) { 
        free(tmp);
        return false;
    }

    printf("eye color is: %s\n", tmp);

    bool result = is_valid_eye_color(tmp);
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

bool parse_pid(char *cp) {
    const int offset = 4;
    char * tmp = calloc(50, sizeof(char));
    
    cp += offset;
    int j = 0;     
        
    for(char* i = cp; *i != ' ' && *i != '\n'; i++) {
        tmp[j++] = *i;
    }
        
    if(j != 9) {
        free(tmp);
        return false;
    }
    
    //FIX THIS AND MAKE OWN STRTOL FOR PASSPORT

    for(size_t i = 0; i < strlen(tmp); i++) {
        if(is_valid_pid_num(tmp[i]) == false) {
            return false;
        }
    }
    
    return true;
    /*
    char* p_end;
    long int num = strtol(tmp, &p_end, 10);  //REFACTOR TO JUST CONVERT NUM AND CHECK RETURN VAL
    free(tmp);
        
    if((errno == LONG_MAX || errno == LONG_MIN) && num == 0) {
        return false;
    } else {
        return true;
    }*/

}

void validate_line(char *line, bool *entry) {
    //TODO REFACTOR
    //TODO BASED ON A ENTRY ARRAY, CALL METHODS TO VERIFY SPECIFIC FIELDS
    
    char *has_bday = strstr(line, "byr");

    if(has_bday != NULL) {
        bool ret = parse_birth_year(has_bday);
    
        if(ret == true) {
            printf("yay bday true!\n");
            entry[0] = true;
        } else {
            printf("nooo shot, bday false!\n");
            entry[0] = false;
        }
    }

    char *has_issue_year = strstr(line, "iyr");

    if(has_issue_year != NULL) {
        bool ret = parse_issue_year(has_issue_year);
    
        if(ret == true) {
            printf("yay issue year true!\n");
            entry[1] = true;
        } else {
            printf("nooo shot, issue year false!\n");
            entry[1] = false;
        }
    }

    char *has_exp_year = strstr(line, "eyr");

    if(has_exp_year != NULL) {
        bool ret = parse_exp_year(has_exp_year);

        if(ret == true) {
            printf("yay exp year true!\n");
            entry[2] = true;
        } else {
            printf("nooo shot, exp year false!\n");
            entry[2] = false;
        }
    }
    //HERE FIX!!!!
    char *has_height = strstr(line, "hgt");

    if(has_height != NULL) {
        bool ret = parse_height(has_height);

        if(ret == true) {
            printf("yay height true!\n");
            entry[3] = true;
        } else {
            printf("noo shot, height false!");
            entry[3] = false;
        }
    }

    char *has_hair_color = strstr(line, "hcl");

    if(has_hair_color != NULL) {
        bool ret = parse_hair_color(has_hair_color);

        if(ret == true) {
            printf("yay hair color true!\n");
            entry[4] = true;
        } else {
            printf("noo shot, hair color false!\n");
            entry[4] = false;
        }
    }

    char *has_eye_color = strstr(line, "ecl");

    if(has_eye_color != NULL) {
        bool ret = parse_eye_color(has_eye_color);

        if(ret == true) {
            printf("yay eye color true!\n");
            entry[5] = true;
        } else {
            printf("noo shot, eye color false!\n");
            entry[5] = false;
        }
    }

    char *has_pid = strstr(line, "pid");

    if(has_pid != NULL) {
        bool ret = parse_pid(has_pid);

        if(ret == true) {
            printf("yay pid true!\n");
            entry[6] = true;
        } else {
            printf("noo shot, pid false!\n");
            entry[6] = false;
        }
    }
    
}

bool is_valid(bool *entry, size_t len) {
    for(size_t i = 0; i < len; i++) {
        if(entry[i] == false) {
            return false;
        }
    }
    return true;
}