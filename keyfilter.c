#include <stdio.h>
#include <string.h>

int iscontaining(char *slice, char *in);

void str_toupper(char *input) 
{
    for (unsigned long i = 0; i < strlen(input); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = input[i] - 32;
        }
    }
}

void compare(char *input, char *buf, char *out, int out_idx) 
{
    if (strlen(input) == 0) {
        printf("Unspecified input.\n");
    }
    
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

int isletter(char c) 
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'A')) {
        return 1;
    }

    return 0;
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

int main(int argc, char *argv[]) 
{
    char buffer[255];
    char enabled[255];
    
    if (argc == 1) {
        int i = 0;
        while (fgets(buffer, 100, stdin)) {
            if (isletter(buffer[0])) {
                enabled[i] = buffer[0];
                i++;
            }
        }
    } else if (argc == 2) {
        int j = 0;
        while (fgets(buffer, 100, stdin)) {
            if (iscontaining(argv[1], buffer)) {
                compare(argv[1], buffer, enabled, j);
                j++;
                // printf("%s\n", buffer);
            } else {
                continue;
            }
        }
    } else {
        printf("Invalid argument count.\n");
        return 1;
    }
    
    switch (enabled[0]) {
    case '\0':
        printf("Not found.\n");
        break;

    case '0':
        printf("Found: %s\n", enabled);
        break;

    default:
        printf("Enable: %s\n", enabled);
        break;
    }

    return 0;
}
