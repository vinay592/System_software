/*
================================================================================
Name : 8d
Author : Vinay V Bhandare
Description : Catch SIGALRM using alarm()
Date : 20th Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
    printf("Caught SIGALRM from alarm()\n");
    exit(0);
}

int main()
{
    signal(SIGALRM, handler);
    alarm(5);
    while(1)
    {
    }
    return 0;
}

/* Output (after 5 seconds):
Caught SIGALRM from alarm()
*/

