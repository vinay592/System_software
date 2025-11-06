/*
================================================================================
Name : 2
Author : Vinay V Bhandare
Description : Write a program to print the system resource limits. Use getrlimit system call
Date : 20th Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

void display(const char *txt, int res)
{
    struct rlimit r;
    if (getrlimit(res, &r) == -1)
    {
        perror("getrlimit");
        return;
    }

    printf("%-18s : ", txt);

    if (r.rlim_cur == RLIM_INFINITY)
        printf("soft = unlimited, ");
    else
        printf("soft = %ld, ", (long)r.rlim_cur);

    if (r.rlim_max == RLIM_INFINITY)
        printf("hard = unlimited\n");
    else
        printf("hard = %ld\n", (long)r.rlim_max);
}

int main()
{
    printf("System Resource Limits\n\n");

    display("CPU time", RLIMIT_CPU);
    display("File size", RLIMIT_FSIZE);
    display("Data seg size", RLIMIT_DATA);
    display("Stack size", RLIMIT_STACK);
    display("Core size", RLIMIT_CORE);
    display("Resident set", RLIMIT_RSS);
    display("Processes", RLIMIT_NPROC);
    display("Open files", RLIMIT_NOFILE);
    display("Mem lock", RLIMIT_MEMLOCK);
    display("Addr space", RLIMIT_AS);
#ifdef RLIMIT_NICE
    display("Nice", RLIMIT_NICE);
#endif
#ifdef RLIMIT_RTPRIO
    display("Rt prio", RLIMIT_RTPRIO);
#endif
    return 0;
}

/*output

CPU time           : soft = unlimited, hard = unlimited
File size          : soft = unlimited, hard = unlimited
Data seg size      : soft = unlimited, hard = unlimited
Stack size         : soft = 8388608, hard = unlimited
Core size          : soft = 0, hard = unlimited
Resident set       : soft = unlimited, hard = unlimited
Processes          : soft = 30419, hard = 30419
Open files         : soft = 1024, hard = 1048576
Mem lock           : soft = 1012699136, hard = 1012699136
Addr space         : soft = unlimited, hard = unlimited
Nice               : soft = 0, hard = 0
Rt prio            : soft = 0, hard = 0
 
 */
