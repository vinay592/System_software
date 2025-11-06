/*
================================================================================
Name : 24
Author : Vinay V Bhandare
Description : Creates a System V message queue and prints its key and ID
Date : 26th Sept 2025
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
    key_t key;
    int msgid;

    key = ftok(".", 'M');
    if (key == -1)
    {
        perror("Failed to generate key");
        exit(1);
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        perror("Failed to create message queue");
        exit(1);
    }

    printf("Message Queue Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}

/* 
Sample Output:
$ ./a.out
Message Queue Key: 1292503143
Message Queue ID: 0
*/

