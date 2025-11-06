/*
================================================================================
Name : 13a
Author : Vinay V Bhandare
Description : Program tries to catch SIGSTOP
Date : 21st Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
    printf("Caught signal %d\n", sig);
}

int main()
{
    printf("Process PID: %d. Waiting for SIGSTOP...\n", getpid());

    signal(SIGSTOP, handler);  // attempt to catch SIGSTOP

    while(1)
    {
        printf("Running...\n");
        sleep(2);
    }

    return 0;
}

/* Output:
Process PID: 25835. Waiting for SIGSTOP...
Running...
Running...
Running...
Running...
Running...
Running...
Running...
//Run the stopsig 13b parallelly and give it this process ID the the running stops
*/

