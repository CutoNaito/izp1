#include <stdio.h>
#include <string.h>
#include "lib.h"

/* FUNCTION DEFINITIONS */
int compare(char *input, char *buf, char *out, int out_idx) 
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

    /* Check for found */
    if (iscontaining(input, buf) && strlen(input) == strlen(buf)-1) {
        found(buf, out);
        return 2;
    } else {
        unsigned long i = 0;
        while(i+1 < strlen(buf)) {
            if (buf[i] == input[i]) {
                i++;
            } else if (i > 0) {
                out[0] = '2';
                if (!contains_c(buf[i], out)) {
                    out[out_idx+1] = buf[i]; 
                    return 1;
                    break;
                }

                break;
            } else {
                out[0] = '0';
                break;
            }
        }
    } 

    return 0;
}

void found(char *input, char *buf) 
{
    /*
     * Assigns one string to the other
     *
     * Used on the "Found" state (if arg == address)
     */
    buf[0] = '1';
    for (unsigned long i = 0; i < strlen(input); i++) {
        if (i+1 <= strlen(buf) && input[i] != '\n') {
            printf("%c\n", input[i]);
            buf[i+1] = input[i];
        }
    }
}

int contains_c(char input, char *str)
{
    /*
     * Checks if string contains a specified character
     */
    str_toupper(&input);
    str_toupper(str);

    for (unsigned long i = 0; i < strlen(str); i++) {
        if (str[i] == input) {
            return 1;
        }
    }

    return 0;
}

int iscontaining(char *slice, char *in) 
{
    /*
     * Checks if string contains a specified string (slice)
     */
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
    /*
     * Returns true (1) if specified character is a letter
     */
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'A')) {
        return 1;
    }

    return 0;
}

void sort(char *input) 
{
    /*
     * BubbleSort. Sorts a specified array.
     */
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
    /*
     * Converts a string to uppercase
     */
    for (unsigned long i = 0; i < strlen(input); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = input[i] - 32;
        }
    }
}
