/*
================================================================================
Name : 19e
Author : Vinay V Bhandare
Description : Create FIFO using mkfifo library function
Date : 23rd Sept 2025
================================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    if (mkfifo("fifo_lib", 0666) == -1)
    {
        perror("mkfifo failed");
        return 1;
    }
    printf("FIFO created with mkfifo library function\n");
    return 0;
}

/* Output:
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/19/e$ ./a.out
FIFO created with mkfifo library function
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/19/e$ ls -l
total 20
-rwxrwxr-x 1 vinay-v-bhandare vinay-v-bhandare 16048 Sep 23 15:18 a.out
prw-rw-r-- 1 vinay-v-bhandare vinay-v-bhandare     0 Sep 23 15:18 fifo_lib
-rw-rw-r-- 1 vinay-v-bhandare vinay-v-bhandare   683 Sep 23 15:18 myfifo.c
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/19/e$ 
*/

