#include <stdio.h>
#include <string.h>
#include "lib.h"

int main(int argc, char *argv[]) 
{
    char buffer[255]; /* Buffer, used for input (file) */
    char enabled[255]; /* Output string */
    
    if (argc == 1) {
        enabled[0] = '2';
        int i = 0;
        while (fgets(buffer, 100, stdin) != NULL) {
            if (!contains_c(buffer[0], enabled)) {
                enabled[i+1] = buffer[0];
                enabled[i+2] = '\0';
                i++;
            }
        }
    } else if (argc == 2) {
        int count = 0;
        int j = 0;
        /* Input reading into buffer line by line */
        while (fgets(buffer, 100, stdin) != NULL) {
            if (iscontaining(argv[1], buffer)) {
                if (compare(argv[1], buffer, enabled, j) == 1) {
                    count++;
                }

                j++;
            } else {
                continue;
            }
        }
    } else {
        printf("Invalid argument count.\n");
        return 1;
    }
    
    /* Assigns "Not found" state, if no state was assigned */
    if (enabled[0] != '1' && enabled[0] != '2') {
        enabled[0] = '0';
    }

    /* Evaluation */
    switch (enabled[0]) {
    case '0':
        printf("Not found.\n");
        break;

    case '1':
        printf("Found: %s\n", strchr(enabled, enabled[1]));
        break;

    case '2':
        sort(enabled);
        printf("Enable: %s\n", strchr(enabled, enabled[1]));
        break;

    default:
        printf("Something went wrong.\n");
        return -1;
    }

    return 0;
}
