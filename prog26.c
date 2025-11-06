/*
================================================================================
Name : 26
Author : Vinay V Bhandare
Description : Sends messages to a System V message queue and can be verified with ipcs -q
Date : 26th Sept 2025
================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

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

    key = ftok(".", 'B');           // generate unique key
    msgid = msgget(key, IPC_CREAT | 0666);   // create or get queue

    if (msgid == -1)
    {
        perror("msgget");
        return 1;
    }

    message.mtype = 1;
    strcpy(message.mtext, "Hello from sender process");

    if (msgsnd(msgid, &message, sizeof(message.mtext), 0) == -1)
    {
        perror("msgsnd");
        return 1;
    }

    printf("Message sent successfully to queue (msgid = %d)\n", msgid);
    return 0;
}


/* 
Sample Output:
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/26$ ./a.out
Enter message to send: Hii
Message sent successfully.
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/26$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4d0a0867 0          vinay-v-bh 666        0            0           
0x4d0a0868 1          vinay-v-bh 666        0            0           
0x4d0a0869 2          vinay-v-bh 666        128          1           


*/

