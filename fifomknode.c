/*
================================================================================
Name : 19a
Author : Vinay V Bhandare
Description : Create FIFO using mknod command (invoked from C)
Date : 23rd Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    if (system("mknod fifo_cmd_a p") == -1)
    {
        perror("system");
        return 1;
    }
    printf("FIFO created using mknod command\n");
    return 0;
}

/* Output:
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/19/a$ ./a.out
FIFO created using mknod command
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/19/a$ ls -l
total 20
-rwxrwxr-x 1 vinay-v-bhandare vinay-v-bhandare 16048 Sep 23 15:11 a.out
prw-rw-r-- 1 vinay-v-bhandare vinay-v-bhandare     0 Sep 23 15:12 fifo_cmd_a
-rw-rw-r-- 1 vinay-v-bhandare vinay-v-bhandare   649 Sep 23 15:11 fifomknode.c

*/

