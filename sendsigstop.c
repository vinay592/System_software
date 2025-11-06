/*
================================================================================
Name : 13b
Author : Vinay V Bhandare
Description : Program sends SIGSTOP to another process using kill()
Date : 21st Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <PID of target process>\n", argv[0]);
        return 1;
    }

    pid_t target = atoi(argv[1]);
    printf("Sending SIGSTOP to PID %d\n", target);

    if (kill(target, SIGSTOP) == -1)
    {
        perror("kill failed");
        return 1;
    }

    printf("SIGSTOP sent successfully.\n");
    return 0;
}

/* Output:
send_sigstop 23697
Sending SIGSTOP to PID 23697
SIGSTOP sent successfully.
Observation: The target process stops immediately. It does not execute the handler.
*/

