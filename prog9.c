/*
================================================================================
Name : 9
Author : Vinay V Bhandare
Description : Ignore SIGINT first, then reset default action
Date : 20th Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
    printf("This should not be printed if SIGINT is ignored\n");
}

int main()
{
    printf("SIGINT will be ignored for 5 seconds. Try pressing Ctrl+C...\n");

    signal(SIGINT, SIG_IGN);

    for (int i = 5; i > 0; i--)
    {
        printf("%d...\n", i);
        sleep(1);
    }

    printf("Resetting SIGINT to default action. Press Ctrl+C now will terminate.\n");
    signal(SIGINT, SIG_DFL);

    while(1)
    {
        sleep(1);
    }

    return 0;
}

/* Output:
SIGINT will be ignored for 5 seconds. Try pressing Ctrl+C...
5...
4...
3...
2...
1...
To exit
^C
*/

