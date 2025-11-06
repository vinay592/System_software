/*
================================================================================
Name : 17b
Author : Vinay V Bhandare
Description : Execute ls -l | wc using dup2
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
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        exit(1);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        execlp("wc", "wc", NULL);
        exit(1);
    }

    return 0;
}

/* Output:
 4      29     231
*/

