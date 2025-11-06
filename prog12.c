/*
================================================================================
Name : 12
Author : Vinay V Bhandare
Description : Create an orphan process. Child kills parent using kill()
Date : 20th Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("Child process running. PID: %d, Parent PID: %d\n", getpid(), getppid());
        sleep(2);
        printf("Child sending SIGKILL to parent PID: %d\n", getppid());
        kill(getppid(), SIGKILL);
        printf("Child is now orphaned. My new parent PID: %d\n", getppid());
        sleep(2);
        printf("Child exiting.\n");
    }
    else
    {
        printf("Parent process running. PID: %d\n", getpid());
        while(1)
        {
            sleep(1);
        }
    }

    return 0;
}

/* Output (sample):
Parent process running. PID: 25148
Child process running. PID: 25149, Parent PID: 25148
Child sending SIGKILL to parent PID: 25148
Child is now orphaned. My new parent PID: 25148
Killed
Child exiting.
*/
