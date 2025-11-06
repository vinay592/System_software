/*
================================================================================
Name : 28
Author : Vinay V Bhandare
Description : Write a program to change the exiting message queue permission.
              (use msqid_ds structure)
Date : 29th Sept 2025
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() 
{
    key_t key;
    key = ftok("msgfile", 65);

    int msqid;
    msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1) 
    {
        perror("msgget failed");
        exit(1);
    }

    struct msqid_ds buf;

    if (msgctl(msqid, IPC_STAT, &buf) == -1) 
    {
        perror("msgctl get failed");
        exit(1);
    }

    printf("Old permissions: %o\n", buf.msg_perm.mode);

    buf.msg_perm.mode = 0770;

    if (msgctl(msqid, IPC_SET, &buf) == -1) 
    {
        perror("msgctl set failed");
        exit(1);
    }

    printf("New permissions: %o\n", buf.msg_perm.mode);

    return 0;
}

/* 
Output:
Old permissions: 666
New permissions: 660

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x4d0a0867 0          vinay-v-bh 666        0            0
0x4d0a0868 1          vinay-v-bh 666        0            0
0x4d0a0869 2          vinay-v-bh 666        512          4
0x4d0a086a 3          vinay-v-bh 666        0            0
0xffffffff 4          vinay-v-bh 660        0            0
*/

