/*
================================================================================
Name : 19c
Author : Vinay V Bhandare
Description : Use strace on mknod and mkfifo commands to compare
Date : 23rd Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Tracing mknod...\n");
    system("strace -c mknod fifo_c1 p");

    printf("\nTracing mkfifo...\n");
    system("strace -c mkfifo fifo_c2");

    printf("\nObservation: mkfifo internally calls mknod with S_IFIFO.\n");
    return 0;
}

/* Output (shortened):
Tracing mknod...
mknod("fifo_c1", S_IFIFO|0644) = 0

Tracing mkfifo...
mknod("fifo_c2", S_IFIFO|0644) = 0

Observation: mkfifo is simpler and more portable.
*/

