/*
================================================================================
Name : 31
Author : Vinay V Bhandare
Description : Write a program to create a semaphore and initialize value to the semaphore.
              a. create a binary semaphore
              b. create a counting semaphore
Date : 29th Sept 2025
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun 
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() 
{
    key_t key1;
    key1 = ftok("binsem", 65);

    int semid1;
    semid1 = semget(key1, 1, 0666 | IPC_CREAT);
    if (semid1 == -1) 
    {
        perror("semget binary failed");
        exit(1);
    }

    union semun arg1;
    arg1.val = 1;
    if (semctl(semid1, 0, SETVAL, arg1) == -1) 
    {
        perror("semctl binary set failed");
        exit(1);
    }

    printf("Binary semaphore created with id %d and initialized to %d\n", semid1, arg1.val);

    key_t key2;
    key2 = ftok("countsem", 75);

    int semid2;
    semid2 = semget(key2, 1, 0666 | IPC_CREAT);
    if (semid2 == -1) 
    {
        perror("semget counting failed");
        exit(1);
    }

    union semun arg2;
    arg2.val = 5;
    if (semctl(semid2, 0, SETVAL, arg2) == -1) 
    {
        perror("semctl counting set failed");
        exit(1);
    }

    printf("Counting semaphore created with id %d and initialized to %d\n", semid2, arg2.val);

    return 0;
}

/*
Output:
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/31$ ./a.out
Binary semaphore created with id 0 and initialized to 1
Counting semaphore created with id 0 and initialized to 5
*/

