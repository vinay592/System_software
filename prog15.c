/*
================================================================================
Name : 15
Author : Vinay V Bhandare
Description : Program where parent sends data to child process using a pipe
Date : 21st Sept 2025
================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int fd[2];
    char buffer[50];
    pid_t pid;

    pipe(fd);
    pid = fork();

    if (pid == 0) {
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    } else {
        close(fd[0]);
        char msg[] = "Hello from parent";
        write(fd[1], msg, strlen(msg) + 1);
        close(fd[1]);
    }

    return 0;
}

/* Output:
Child received: Hello from parent
*/

