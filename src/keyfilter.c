#include <stdio.h>
#include <string.h>
#include "lib.h"

int main(int argc, char *argv[]) 
{
    char buffer[255] = {}; /* Buffer, used for input (file) */
    Result result = {
        .state = 0,
        .result = {}
    }; /* Output string */
    
    if (argc == 1 || strcmp(argv[1], "") == 0) {
        result.state = 2;
        int i = 0;
        while (fgets(buffer, 128, stdin) != NULL) {
            if (!contains_c(buffer[0], result.result)) {
                result.result[i] = buffer[0];
                result.result[i+1] = '\0';
                i++;
            }
        }
    } else if (argc == 2) {
        int count = 0;
        int j = 0;
        char tempbuffer[128] = {};
        /* Input reading into buffer line by line */
        while (fgets(buffer, 128, stdin) != NULL) {
            if (iscontaining(argv[1], buffer)) {
                if (compare(argv[1], buffer, &result, count) == 1) {
                    strcpy(tempbuffer, buffer);
                    count++;
                } else if (compare(argv[1], buffer, &result, count) == 2) {
                    break;
                }

                j++;
            } else {
                continue;
            }
        }

        if (j == 1) {
            result.state = 1;
            str_toupper(tempbuffer);
            strcpy(result.result, tempbuffer);
        }
    } else {
        fprintf(stderr, "Invalid argument count.\n");
        return 1;
    }
    
    /* Assigns "Not found" state, if no state was assigned */
    if (result.state != 1 && result.state != 2) {
        result.state = 0;
    }

    /* Evaluation */
    switch (result.state) {
    case 0:
        printf("Not found\n");
        break;

    case 1:
        printf("Found: %s\n", result.result);
        break;

    case 2:
        sort(result.result);
        printf("Enable: %s\n", result.result);
        break;

    default:
        fprintf(stderr, "Something went wrong.\n");
        return 1;
    }

    return 0;
}
