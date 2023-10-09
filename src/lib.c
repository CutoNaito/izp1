#include <stdio.h>
#include <string.h>
#include "lib.h"

/* FUNCTION DEFINITIONS */
void compare(char *input, char *buf, char *out, int out_idx) 
{
    /* Compares two strings and adds the first non-common character to a reserved buffer 
     *
     * If the two specified strings don't have any common characters, adds a NULL character.
     * If the two specified strings are equivalent, adds a TAB.
     * */
    if (strlen(input) == 0) {
        printf("Unspecified input.\n");
    }
    
    /* Converts both specified strings to uppercase */
    str_toupper(input);
    str_toupper(buf);

    if (iscontaining(input, buf) && strlen(input) == strlen(buf)-1) {
        /* temp */
        out[0] = '\t';
    } else {
        int i = 0;
        while(i+1 < (int)strlen(buf)) {
            if (buf[i] == input[i]) {
                i++;
            } else if (i > 0) {
                out[out_idx] = buf[i]; 
                break;
            } else {
                out[out_idx] = '\0';
                break;
            }
        }
    } 
}

int iscontaining(char *slice, char *in) 
{
    str_toupper(slice);
    str_toupper(in);

    int result = 1;
    for (unsigned long i = 0; i < strlen(slice) && i < strlen(in); i++) {
        if (slice[i] != in[i]) {
            result = 0;
            break;
        }
    }

    return result;
}

int isletter(char c) 
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'A')) {
        return 1;
    }

    return 0;
}

void sort(char *input) 
{
    for (unsigned long i = 0; i < strlen(input); ++i) {
        for (unsigned long j = 0; j < strlen(input) - i - 1; ++j) {
            if (input[i] > input[i+1]) {
                char temp = input[i];
                input[i] = input[i+1];
                input[i+1] = temp;
            }
        }
    }
}

void str_toupper(char *input) 
{
    for (unsigned long i = 0; i < strlen(input); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = input[i] - 32;
        }
    }
}
