/*
================================================================================
Name : 5
Author : Vinay V Bhandare
Description : 
Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory
Date : 20th Sept 2025
================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdlib.h>

int main()
{
    struct rlimit lim;

    long arg_max = sysconf(_SC_ARG_MAX);
    printf("Maximum length of arguments to exec functions : %ld\n", arg_max);

    if (getrlimit(RLIMIT_NPROC, &lim) == -1)
    {
        perror("getrlimit");
        exit(1);
    }
    printf("Maximum number of processes per user id       : %ld\n", (long)lim.rlim_cur);

    long clk_tck = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks per second (jiffy)     : %ld\n", clk_tck);

    if (getrlimit(RLIMIT_NOFILE, &lim) == -1)
    {
        perror("getrlimit");
        exit(1);
    }
    printf("Maximum number of open files                 : %ld\n", (long)lim.rlim_cur);

    long page_size = sysconf(_SC_PAGESIZE);
    printf("Size of a page (bytes)                       : %ld\n", page_size);

    long phys_pages = sysconf(_SC_PHYS_PAGES);
    printf("Total number of pages in physical memory     : %ld\n", phys_pages);

    long avail_pages = sysconf(_SC_AVPHYS_PAGES);
    printf("Number of currently available pages          : %ld\n", avail_pages);

    return 0;
}
/*
Output:
Maximum length of arguments to exec functions : 2097152
Maximum number of processes per user id       : 30419
Number of clock ticks per second (jiffy)     : 100
Maximum number of open files                 : 1024
Size of a page (bytes)                       : 4096
Total number of pages in physical memory     : 1977930
Number of currently available pages          : 695035
*/
