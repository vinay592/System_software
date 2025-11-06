/*
================================================================================
Name : 19d
Author : Vinay V Bhandare
Description : Create FIFO using mknod system call
Date : 23rd Sept 2025
================================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    if (mknod("fifo_sys", S_IFIFO | 0666, 0) == -1)
    {
        perror("mknod failed");
        return 1;
    }
    printf("FIFO created with mknod system call\n");
    return 0;
}

/* Output:
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/19/d$ ./a.out
FIFO created with mknod system call
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/19/d$ ls -l
total 20
-rwxrwxr-x 1 vinay-v-bhandare vinay-v-bhandare 16048 Sep 23 15:17 a.out
prw-rw-r-- 1 vinay-v-bhandare vinay-v-bhandare     0 Sep 23 15:17 fifo_sys
-rw-rw-r-- 1 vinay-v-bhandare vinay-v-bhandare   699 Sep 23 15:16 mknod.c

*/

