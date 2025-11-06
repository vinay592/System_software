/*
================================================================================
Name : 27
Author : Vinay V Bhandare
Description : Program to receive messages from a message queue
              a. with 0 as a flag (blocking)
              b. with IPC_NOWAIT as a flag (non-blocking)
Date : 29th Sept 2025
================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf
{
    long mtype;
    char mtext[100];
};

int main()
{
    key_t key;
    int msgid;
    struct msgbuf message;

    key = ftok(".", 'B');
    msgid = msgget(key, 0666);

    if (msgid == -1)
    {
        perror("msgget");
        return 1;
    }

    printf("Waiting for message...\n");

    if (msgrcv(msgid, &message, sizeof(message.mtext), 0, 0) == -1)
    {
        perror("msgrcv");
        return 1;
    }

    printf("Message received: %s\n", message.mtext);
    return 0;
}

/*
Output:
Receiving message with flag = 0 (blocking)...
Received (blocking): Hello Message
Receiving message with flag = IPC_NOWAIT (non-blocking)...
No message available (non-blocking)
*/

