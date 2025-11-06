/*
================================================================================
Name : 1 c
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

void prof_handler(int s) {
    printf("[PROF] Profiling timer expired!\n");
}

int main() {
    struct itimerval prof_t;
    signal(SIGPROF, prof_handler);

    prof_t.it_value.tv_sec = 10;
    prof_t.it_value.tv_usec = 0;

    prof_t.it_interval.tv_sec = 0;
    prof_t.it_interval.tv_usec = 10;

    if (setitimer(ITIMER_PROF, &prof_t, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    while (1) {
    }
}
/*
[PROF] Profiling timer expired!
[PROF] Profiling timer expired!
[PROF] Profiling timer expired!
...
*/
