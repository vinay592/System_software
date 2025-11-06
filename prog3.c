/*
================================================================================
Name : 3
Author : Vinay V Bhandare
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date : 20th Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
    struct rlimit lim;

    if (getrlimit(RLIMIT_NOFILE, &lim) == -1)
    {
        perror("getrlimit");
        exit(1);
    }

    printf("Before change:\n");
    printf("Soft limit = %ld, Hard limit = %ld\n", (long)lim.rlim_cur, (long)lim.rlim_max);

    lim.rlim_cur = 2048;

    if (setrlimit(RLIMIT_NOFILE, &lim) == -1)
    {
        perror("setrlimit");
        exit(1);
    }

    if (getrlimit(RLIMIT_NOFILE, &lim) == -1)
    {
        perror("getrlimit");
        exit(1);
    }

    printf("After change:\n");
    printf("Soft limit = %ld, Hard limit = %ld\n", (long)lim.rlim_cur, (long)lim.rlim_max);

    return 0;
}
/*
 Output:
 Before change:
 Soft limit = 1024, Hard limit = 1048576
 After change:
 Soft limit = 2048, Hard limit = 1048576 
 */
