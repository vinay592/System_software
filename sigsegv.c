/*
================================================================================
Name : 10a
Author : Vinay V Bhandare
Description : Catch SIGSEGV using sigaction
Date : 20th Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig, siginfo_t *info, void *ucontext)
{
    printf("Caught SIGSEGV using sigaction\n");
    exit(1);
}

int main()
{
    struct sigaction sa;
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGSEGV, &sa, NULL);

    int *p = NULL;
    *p = 10;

    return 0;
}

/* Output:
Caught SIGSEGV using sigaction
*/

