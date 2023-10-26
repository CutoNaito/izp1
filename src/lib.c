#include <stdio.h>
#include <string.h>
#include "lib.h"

/* FUNCTION DEFINITIONS */
int compare(char *input, char *buf, Result *out, int out_idx) 
{
    /* Compares two strings and adds the first non-common character to a reserved buffer 
     *
     * If the two specified strings don't have any common characters, adds a NULL character.
     * If the two specified strings are equivalent, adds a TAB.
     * */
    
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
            /* Continues if the chars are equal */
            if (buf[i] == input[i]) {
                i++;

            /* If atleast one char is equal */
            } else if (i > 0) {
                out->state = 2;

                if (!contains_c(buf[i], out->result)) {
                    out->result[out_idx] = buf[i]; 
                    out->result[out_idx+1] = '\0';
                    return 1;
                    break;
                }

                break;
            } else {
                out->state = 0;
                break;
            }
        }
    } 

    return 0;
}

void found(char *input, Result *out) 
{
    /*
     * Assigns one string to the other
     *
     * Used on the "Found" state (if arg == address)
     */
    out->state = 1;
    for (unsigned long i = 0; i < strlen(input); i++) {
        if (i <= strlen(out->result) && input[i] != '\n') {
            out->result[i] = input[i];
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

    for (unsigned long i = 0; i < strlen(slice) && i < strlen(in); i++) {
        if (slice[i] != in[i]) {
            return 0;
            break;
        }
    }

    return 1;
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
    char temp;
    str_toupper(input);
    for (unsigned long i = 0; i < strlen(input); i++) {
        for (unsigned long j = 0; j < strlen(input)-1; j++) {
            if (input[j] > input[j+1]) {
                temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
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
