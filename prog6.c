/*
================================================================================
Name : 6
Author : Vinay V Bhandare
Description : Write a simple program to create three threads.
Date : 20th Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* task(void* arg)
{
    int id = *(int*)arg;
    printf("Thread %d is running\n", id);
    return NULL;
}

int main()
{
    pthread_t t1, t2, t3;
    int id1 = 1, id2 = 2, id3 = 3;

    if (pthread_create(&t1, NULL, task, &id1) != 0)
    {
        perror("pthread_create");
        exit(1);
    }

    if (pthread_create(&t2, NULL, task, &id2) != 0)
    {
        perror("pthread_create");
        exit(1);
    }

    if (pthread_create(&t3, NULL, task, &id3) != 0)
    {
        perror("pthread_create");
        exit(1);
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("All threads finished\n");

    return 0;
}
/*
Output:
Thread 1 is running
Thread 2 is running
Thread 3 is running
All threads finished
*/ 
