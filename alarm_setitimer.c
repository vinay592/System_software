/*
================================================================================
Name : 8e
Author : Vinay V Bhandare
Description : Catch SIGALRM using setitimer()
Date : 20th Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig)
{
    printf("Caught SIGALRM from setitimer()\n");
    exit(0);
}

int main()
{
    struct itimerval t;
    signal(SIGALRM, handler);
    t.it_value.tv_sec = 5;
    t.it_value.tv_usec = 0;
    t.it_interval.tv_sec = 0;
    t.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &t, NULL);
    while(1)
    {
    }
    return 0;
}

/* Output (after 5 seconds):
Caught SIGALRM from setitimer()
*/

