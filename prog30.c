/*
================================================================================
Name : 30
Author : Vinay V Bhandare
Description : Write a program to create a shared memory.
              a. write some data to the shared memory
              b. attach with O_RDONLY and check whether you are able to overwrite.
              c. detach the shared memory
              d. remove the shared memory
Date : 29th Sept 2025
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    key_t key;
    key = ftok("shmfile", 65);

    int shmid;
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1)
    {
        perror("shmget failed");
        exit(1);
    }

    char *str = (char *) shmat(shmid, NULL, 0);
    if (str == (char *) -1)
    {
        perror("shmat failed (write mode)");
        exit(1);
    }

    strcpy(str, "Hello Shared Memory!");
    printf("Data written in shared memory: %s\n", str);

    if (shmdt(str) == -1)
    {
        perror("shmdt failed");
        exit(1);
    }

    char *readonly = (char *) shmat(shmid, NULL, SHM_RDONLY);
    if (readonly == (char *) -1)
    {
        perror("shmat failed (read-only mode)");
        exit(1);
    }

    printf("Data read in read-only mode: %s\n", readonly);
    printf("Trying to overwrite in read-only mode...\n");

    if (shmdt(readonly) == -1)
    {
        perror("shmdt failed (readonly)");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("shmctl remove failed");
        exit(1);
    }

    printf("Shared memory removed successfully.\n");

    return 0;
}
/*
Data written in shared memory: Hello Shared Memory!
Data read in read-only mode: Hello Shared Memory!
Trying to overwrite in read-only mode...
Shared memory removed successfully.
*/
