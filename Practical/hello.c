#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];

    while (1) {
        printf("myshell> ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
            break;

        if (strcmp(input, "pwd") == 0) {
            char *dir = getenv("PWD");

            if (dir)
                printf("%s\n", dir);

            continue;
        }

        if (strncmp(input, "echo $", 6) == 0) {
            char *var = input + 6;
            char *value = getenv(var);

            if (value)
                printf("%s\n", value);
            else
                printf("Undefined variable\n");

            continue;
        }

        printf("Unknown command: %s\n", input);
    }

    return 0;
}
