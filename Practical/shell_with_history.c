#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY 10

int main() {
    char *history[MAX_HISTORY];
    int count = 0;
    char buffer[200];

    while (1) {
        printf("myshell> ");
        fgets(buffer, sizeof(buffer), stdin);

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "exit") == 0)
            break;

        if (strcmp(buffer, "history") == 0) {
            for (int i = 0; i < count; i++)
                printf("%d  %s\n", i + 1, history[i]);
            continue;
        }

        if (strlen(buffer) > 0) {
            if (count == MAX_HISTORY) {
                free(history[0]);

                for (int i = 1; i < MAX_HISTORY; i++)
                    history[i - 1] = history[i];

                count--;
            }

            history[count] = malloc(strlen(buffer) + 1);
            strcpy(history[count], buffer);
            count++;
        }
    }

    for (int i = 0; i < count; i++)
        free(history[i]);

    return 0;
}
