/*
================================================================================
Name : 11
Author : Vinay V Bhandare
Description : Ignore SIGINT first, then reset default action using sigaction
Date : 20th Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    struct sigaction sa_ignore, sa_default;

    sa_ignore.sa_handler = SIG_IGN;
    sigemptyset(&sa_ignore.sa_mask);
    sa_ignore.sa_flags = 0;
    sigaction(SIGINT, &sa_ignore, NULL);

    printf("SIGINT is ignored for 5 seconds. Try pressing Ctrl+C...\n");
    for (int i = 5; i > 0; i--)
    {
        printf("%d...\n", i);
        sleep(1);
    }

    printf("Resetting SIGINT to default action. Press Ctrl+C will terminate now.\n");

    sa_default.sa_handler = SIG_DFL;
    sigemptyset(&sa_default.sa_mask);
    sa_default.sa_flags = 0;
    sigaction(SIGINT, &sa_default, NULL);

    while(1)
    {
        sleep(1);
    }

    return 0;
}

/* Output:
SIGINT is ignored for 5 seconds. Try pressing Ctrl+C...
5...
4...
3...
2...
1...
Resetting SIGINT to default action. Press Ctrl+C to terminate
^C
*/

