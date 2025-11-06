/*
================================================================================
Name : 1 b
Author : Vinay V Bhandare
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
Date : 20th Sept 2025
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void virt_handler(int sig) {
    printf("[VIRTUAL] Tick received!\n");
}

int main() {
    struct itimerval vtime;
    signal(SIGVTALRM, virt_handler);

    vtime.it_value.tv_sec = 10;
    vtime.it_value.tv_usec = 0;

    vtime.it_interval.tv_sec = 0;
    vtime.it_interval.tv_usec = 10;

    if (setitimer(ITIMER_VIRTUAL, &vtime, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    while (1) {
        for (volatile long i = 0; i < 1000000; i++);
    }
}
/*
[VIRTUAL] Tick received!
[VIRTUAL] Tick received!
[VIRTUAL] Tick received!
...
*/
