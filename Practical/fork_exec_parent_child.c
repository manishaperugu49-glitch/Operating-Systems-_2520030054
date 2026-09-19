#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child Process\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        execlp("ls", "ls", "-l", NULL);

        perror("exec failed");
        exit(1);
    } 
    else {
        printf("Parent Process\n");
        printf("Parent PID: %d\n", getpid());

        wait(NULL);
        printf("Child process completed.\n");
    }

    return 0;
}
