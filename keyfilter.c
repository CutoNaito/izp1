#include <stdio.h>
#include <string.h>

void compare(char *input, char *buf) {
    if (strlen(input) == 0) {
        printf("Unspecified input.\n");
    }

    (void)buf;
}

int isletter(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'A')) {
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        printf("%s\n", argv[1]);
    } else if(argc > 2) {
        printf("Too many arguments.\n");
        return 1;
    }

    char buffer[255];

    while (fgets(buffer, 100, stdin)) {
        if (!isletter(buffer[0])) {
            continue;
        }
        
        if (argc == 1) {
            
        }
        // printf("%s\n", buffer);
    }

    return 0;
}
