/*
================================================================================
Name : 10c
Author : Vinay V Bhandare
Description : Catch SIGFPE using sigaction
Date : 20th Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig, siginfo_t *info, void *ucontext)
{
    printf("Caught SIGFPE using sigaction\n");
    exit(1);
}

int main()
{
    struct sigaction sa;
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGFPE, &sa, NULL);

    int a = 10, b = 0;
    int c = a / b;
    printf("%d\n", c);

    return 0;
}

/* Output:
Caught SIGFPE using sigaction
*/

