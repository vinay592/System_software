/*
================================================================================
Name : 8f
Author : Vinay V Bhandare
Description : Catch SIGVTALRM using setitimer()
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
    printf("Caught SIGVTALRM\n");
    exit(0);
}

int main()
{
    struct itimerval t;
    signal(SIGVTALRM, handler);
    t.it_value.tv_sec = 5;
    t.it_value.tv_usec = 0;
    t.it_interval.tv_sec = 0;
    t.it_interval.tv_usec = 0;
    setitimer(ITIMER_VIRTUAL, &t, NULL);
    while(1)
    {
        for (volatile long i = 0; i < 1000000; i++);
    }
    return 0;
}

/* Output (after ~5 seconds of CPU usage):
Caught SIGVTALRM
*/

