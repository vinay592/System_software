/*
================================================================================
Name : 1 a
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
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void real_handler(int signo) {
    printf("[REAL] Timer expired!\n");
}

int main() {
    struct itimerval tmr;

    if (signal(SIGALRM, real_handler) == SIG_ERR) {
        perror("signal");
        exit(1);
    }

    tmr.it_value.tv_sec = 10;
    tmr.it_value.tv_usec = 0;

    tmr.it_interval.tv_sec = 0;
    tmr.it_interval.tv_usec = 10;

    if (setitimer(ITIMER_REAL, &tmr, NULL) < 0) {
        perror("setitimer");
        exit(1);
    }

    for (;;) {
        pause();
    }
}

/*
 * Output:
[REAL] Timer expired!
[REAL] Timer expired!
[REAL] Timer expired!
...
