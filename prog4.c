/*
================================================================================
Name : 4
Author : Vinay V Bhandare
Description : Write a program to measure how much time is taken to execute 100 getppid () system call. Use time stamp counter.
Date : 20th Sept 2025
================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

uint64_t rdtsc()
{
    unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

int main()
{
    uint64_t start, end;
    int i;
    pid_t pid;

    start = rdtsc();

    for (i = 0; i < 100; i++)
    {
        pid = getppid();
    }

    end = rdtsc();

    printf("Time taken for 100 getppid() calls: %lu cycles\n", end - start);

    return 0;
}
/*
Output:
Time taken for 100 getppid() calls: 115596 cycles

*/
