/*
================================================================================
Name : 22
Author : Vinay V Bhandare
Description : Waits for data on FIFO for 10 seconds using select system call
Date : 26th Sept 2025
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <string.h>

#define PIPE "fifo_select"

int main()
{
    int fd;
    char buffer[128];
    fd_set readfds;
    struct timeval timeout;

    mkfifo(PIPE, 0666);

    fd = open(PIPE, O_RDONLY | O_NONBLOCK);
    if (fd < 0)
    {
        perror("Failed to open FIFO");
        exit(1);
    }

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    int ret = select(fd + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1)
    {
        perror("select failed");
        close(fd);
        exit(1);
    }
    else if (ret == 0)
    {
        printf("No data received in 10 seconds.\n");
    }
    else
    {
        if (FD_ISSET(fd, &readfds))
        {
            int n = read(fd, buffer, sizeof(buffer));
            if (n > 0)
            {
                printf("Received: %s", buffer);
            }
        }
    }

    close(fd);
    unlink(PIPE);
    return 0;
}

/* 
Sample Output 1 (Data arrives within 10 seconds):
$ ./a.out
Received: Hello FIFO

Sample Output 2 (No data within 10 seconds):
$ ./a.out
No data received in 10 seconds.
*/

