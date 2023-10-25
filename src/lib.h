#ifndef __LIB_
#define __LIB_

int compare(char *input, char *buf, char *out, int out_idx);
int contains_c(char input, char *str);
void found(char *input, char *buf);
int iscontaining(char *slice, char *in);
int isletter(char c); /*  */
void sort(char *input); /* BubbleSort. Sorts all characters in a string */
void str_toupper(char *input); /* Converts a string to uppercase */

#endif
