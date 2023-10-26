#ifndef __LIB_
#define __LIB_

typedef struct Result {
    char result[255];
    int state;
} Result;

int compare(char *input, char *buf, Result *out, int out_idx);
int contains_c(char input, char *str);
void found(char *input, Result *out);
int iscontaining(char *slice, char *in);
int isletter(char c); /*  */
void sort(char *input); /* BubbleSort. Sorts all characters in a string */
void str_toupper(char *input); /* Converts a string to uppercase */

#endif
