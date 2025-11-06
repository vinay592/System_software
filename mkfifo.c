/*
================================================================================
Name : 19b
Author : Vinay V Bhandare
Description : Create FIFO using mkfifo command (invoked from C)
Date : 23rd Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    if (system("mkfifo fifo_cmd_b") == -1)
    {
        perror("system");
        return 1;
    }
    printf("FIFO created using mkfifo command\n");
    return 0;
}

/* Output:
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/19/b$ ./a.out
FIFO created using mkfifo command
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/19/b$ ls -l
total 20
-rwxrwxr-x 1 vinay-v-bhandare vinay-v-bhandare 16048 Sep 23 15:13 a.out
prw-rw-r-- 1 vinay-v-bhandare vinay-v-bhandare     0 Sep 23 15:13 fifo_cmd_b
-rw-rw-r-- 1 vinay-v-bhandare vinay-v-bhandare   651 Sep 23 15:13 mkfifo.c
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/19/b$ 

*/

