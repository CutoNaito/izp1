#include <stdio.h>
#include <string.h>
#include "lib.h"

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
