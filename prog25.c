/*
================================================================================
Name : 25
Author : Vinay V Bhandare
Description : Prints detailed information of a System V message queue using msqid_ds
Date : 26th Sept 2025
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main()
{
    key_t key;
    int msgid;
    struct msqid_ds buf;

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

    if (msgctl(msgid, IPC_STAT, &buf) == -1)
    {
        perror("Failed to get message queue info");
        exit(1);
    }

    printf("Access Permissions: %o\n", buf.msg_perm.mode);
    printf("Owner UID: %d\n", buf.msg_perm.uid);
    printf("Owner GID: %d\n", buf.msg_perm.gid);
    printf("Last message sent: %s", ctime(&buf.msg_stime));
    printf("Last message received: %s", ctime(&buf.msg_rtime));
    printf("Last change in queue: %s", ctime(&buf.msg_ctime));
    printf("Current number of bytes in queue: %ld\n", buf.__msg_cbytes);
    printf("Number of messages in queue: %ld\n", buf.msg_qnum);
    printf("Maximum number of bytes allowed: %ld\n", buf.msg_qbytes);
    printf("PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}

/* 
Sample Output:
Access Permissions: 666
Owner UID: 1000
Owner GID: 1000
Last message sent: Thu Jan  1 05:30:00 1970
Last message received: Thu Jan  1 05:30:00 1970
Last change in queue: Mon Sep 29 18:23:52 2025
Current number of bytes in queue: 0
Number of messages in queue: 0
Maximum number of bytes allowed: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0
*/

