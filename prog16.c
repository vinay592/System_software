/*
================================================================================
Name : 16
Author : Vinay V Bhandare
Description : Two-way communication between parent and child using pipes
Date : 21st Sept 2025
================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main()
{
    int pipe1[2], pipe2[2];
    pid_t pid;
    char parent_msg[] = "Hello from parent";
    char child_msg[] = "Hello from child";
    char buffer[50];

    pipe(pipe1);
    pipe(pipe2);

    pid = fork();

    if (pid == 0)
    {
        close(pipe1[1]);
        read(pipe1[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipe1[0]);

        close(pipe2[0]);
        write(pipe2[1], child_msg, strlen(child_msg) + 1);
        close(pipe2[1]);
    }
    else
    {
        close(pipe1[0]);
        write(pipe1[1], parent_msg, strlen(parent_msg) + 1);
        close(pipe1[1]);

        close(pipe2[1]);
        read(pipe2[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
        close(pipe2[0]);
    }

    return 0;
}

/* Output:
Child received: Hello from parent
Parent received: Hello from child
*/

