/*
================================================================================
Name : 29
Author : Vinay V Bhandare
Description : Write a program to remove the message queue.
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
    key = ftok(".",'B');

    int msqid;
    msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1)
    {
        perror("msgget failed");
        exit(1);
    }

    if (msgctl(msqid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl remove failed");
        exit(1);
    }

    printf("Message queue with id %d removed successfully.\n", msqid);

    return 0;
}

/* 
Output:
Message queue with id 4 removed successfully.
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/29$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4d0a0867 0          vinay-v-bh 666        0            0           
0x4d0a0868 1          vinay-v-bh 666        0            0           
0x4d0a0869 2          vinay-v-bh 666        512          4           
0x4d0a086a 3          vinay-v-bh 666        0            0     
*/

