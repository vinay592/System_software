/*
================================================================================
Name : 20b
Author : Vinay V Bhandare
Description : Program to read data from FIFO (one-way communication)
Date : 23rd Sept 2025
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
    int read_fd;
    char buffer[128];

    read_fd = open(PIPE, O_RDONLY);
    if (read_fd < 0)
    {
        perror("Unable to open FIFO for reading");
        exit(1);
    }

    printf("Waiting for messages... (type 'exit' on writer side to stop)\n");

    while (1)
    {
        int bytes = read(read_fd, buffer, sizeof(buffer));
        if (bytes > 0)
        {
            printf("Received: %s", buffer);
            if (strncmp(buffer, "exit", 4) == 0)
                break;
        }
    }

    close(read_fd);
    return 0;
}

/*
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/20$ ./reader
Waiting for messages... (type 'exit' on writer side to stop)
Received: hey there missin u number 18 come backkkkk
Received: love you Viratttt....
Received: exit
*/
