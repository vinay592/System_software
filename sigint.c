/*
================================================================================
Name : 10b
Author : Vinay V Bhandare
Description : Catch SIGINT using sigaction
Date : 20th Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig, siginfo_t *info, void *ucontext)
{
    printf("Caught SIGINT using sigaction\n");
    exit(0);
}

int main()
{
    struct sigaction sa;
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGINT, &sa, NULL);

    printf("Press Ctrl+C to test SIGINT...\n");
    while(1)
    {
        sleep(1);
    }

    return 0;
}

/* Output:
Press Ctrl+C to test SIGINT...
Caught SIGINT using sigaction
*/

