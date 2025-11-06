/*
================================================================================
Name : 7
Author : Vinay V Bhandare
Description : Write a simple program to print the created thread ids.
Date : 20th Sept 2025
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* task(void* arg)
{
    pthread_t tid = pthread_self();
    printf("Thread ID: %lu\n", (unsigned long)tid);
    return NULL;
}

int main()
{
    pthread_t t1, t2, t3;

    if (pthread_create(&t1, NULL, task, NULL) != 0)
    {
        perror("pthread_create");
        exit(1);
    }

    if (pthread_create(&t2, NULL, task, NULL) != 0)
    {
        perror("pthread_create");
        exit(1);
    }

    if (pthread_create(&t3, NULL, task, NULL) != 0)
    {
        perror("pthread_create");
        exit(1);
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}
/*
Output:
Thread ID: 134937055327936
Thread ID: 134937046935232
Thread ID: 134937038542528
*/
