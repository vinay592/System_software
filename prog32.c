/*
================================================================================
Name : 32
Author : Vinay V Bhandare
Description : Implement semaphore to protect critical sections
Date : 29th Sept 2025
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main()
{
    key_t key;
    int semid;

    key = ftok("semfile", 65);
    if (key == -1) {
        perror("ftok failed");
        exit(1);
    }

    // Create a set of 3 semaphores (binary, shm-protect, counting)
    semid = semget(key, 3, 0666 | IPC_CREAT | IPC_EXCL);
    if (semid == -1) {
        perror("semget failed");
        printf("Tip: run `ipcs -s` and `ipcrm -s <id>` to remove old semaphores.\n");
        exit(1);
    }

    union semun arg;

    // Initialize semaphore 0 → binary semaphore
    arg.val = 1;
    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("semctl binary init failed");
        exit(1);
    }

    // Initialize semaphore 1 → protect shared memory
    arg.val = 1;
    if (semctl(semid, 1, SETVAL, arg) == -1) {
        perror("semctl shm-protect init failed");
        exit(1);
    }

    // Initialize semaphore 2 → counting semaphore (say 2 resources)
    arg.val = 2;
    if (semctl(semid, 2, SETVAL, arg) == -1) {
        perror("semctl counting init failed");
        exit(1);
    }

    printf("Semaphore set created with id = %d\n", semid);

    return 0;
}
/*
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/32$ touch semfile
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/32$ gcc prog32.c -o prog32
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/32$ ./prog32
Semaphore set created with id = 1
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/32$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0xffffffff 0          vinay-v-bh 666        1         
0x410a04dc 1          vinay-v-bh 666        3         

vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/32$ ipcrm -s 0
vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/32$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x410a04dc 1          vinay-v-bh 666        3         

vinay-v-bhandare@vinay-v-bhandare-Inspiron-5490:~/SS/HandsOn_2/32$ 

 */
