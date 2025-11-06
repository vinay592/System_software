/*
================================================================================
Name : 14
Author : Vinay V Bhandare
Description : Create a pipe, write to it, read from it and display on monitor
Date : 21st Sept 2025
================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd[2];
    char write_msg[] = "Hello from Vinay";
    char read_msg[50];

    if (pipe(fd) == -1)
    {
        perror("pipe failed");
        exit(1);
    }

    if (fork() == 0)
    {
        close(fd[0]);
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]);
        exit(0);
    }
    else
    {
        close(fd[1]);
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Message from pipe: %s\n", read_msg);
        close(fd[0]);
    }

    return 0;
}

/* Output:
Message from pipe: Hello from Vinay
*/

