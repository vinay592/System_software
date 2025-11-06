/*
================================================================================
Name : 20a
Author : Vinay V Bhandare
Description : Program to send data into FIFO (one-way communication)
Date : 26th Sept 2025
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define PIPE "oneway"

int main()
{
    int wfd;
    char text[128];

    mkfifo(PIPE, 0666);

    wfd = open(PIPE, O_WRONLY);
    if (wfd < 0)
    {
        perror("open failed");
        exit(1);
    }

    while (1)
    {
        printf("Type message: ");
        fgets(text, sizeof(text), stdin);
        write(wfd, text, strlen(text) + 1);
        if (strncmp(text, "exit", 4) == 0)
            break;
    }

    close(wfd);
    return 0;
}
/*
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/20$ ./writer
Type message: hey there missin u number 18 come backkkkk
Type message: love you Viratttt....
Type message: exit
*/
