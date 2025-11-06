/*
================================================================================
Name : 17a
Author : Vinay V Bhandare
Description : Execute ls -l | wc using dup
Date : 23rd Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd[2];
    pipe(fd);

    if (fork() == 0)
    {
        close(fd[0]);
        close(STDOUT_FILENO);
        dup(fd[1]);
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        exit(1);
    }
    else
    {
        close(fd[1]);
        close(STDIN_FILENO);
        dup(fd[0]);
        close(fd[0]);
        execlp("wc", "wc", NULL);
        exit(1);
    }

    return 0;
}

/* Output:
     3      20     157
*/


