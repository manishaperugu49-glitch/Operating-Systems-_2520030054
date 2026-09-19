#include <stdio.h>
#include <string.h>

int main() {
    char input[200];
    char *token;

    printf("Enter command: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    token = strtok(input, " \t");

    printf("Tokens:\n");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " \t");
    }

    return 0;
}
