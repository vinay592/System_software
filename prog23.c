/*
================================================================================
Name : 23
Author : Vinay V Bhandare
Description : Prints maximum number of files a process can open and size of a pipe
Date : 26th Sept 2025
================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    long max_files;
    int pipefd[2];

    max_files = sysconf(_SC_OPEN_MAX);

    if (pipe(pipefd) == -1)
    {
        perror("Failed to create pipe");
        exit(1);
    }

#ifdef F_SETPIPE_SZ
    int pipe_size = fcntl(pipefd[0], F_GETPIPE_SZ);
#else
    int pipe_size = fpathconf(pipefd[0], _PC_PIPE_BUF);
#endif

    printf("Maximum number of files a process can open: %ld\n", max_files);
    printf("Size of pipe (circular buffer) in bytes: %d\n", pipe_size);

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}

/* 
Sample Output:
$ ./a.out
/*
================================================================================
Name : 23
Author : Vinay V Bhandare
Description : Prints maximum number of files a process can open and size of a pipe
Date : 26th Sept 2025
================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    long max_files;
    int pipefd[2];

    max_files = sysconf(_SC_OPEN_MAX);

    if (pipe(pipefd) == -1)
    {
        perror("Failed to create pipe");
        exit(1);
    }

#ifdef F_SETPIPE_SZ
    int pipe_size = fcntl(pipefd[0], F_GETPIPE_SZ);
#else
    int pipe_size = fpathconf(pipefd[0], _PC_PIPE_BUF);
#endif

    printf("Maximum number of files a process can open: %ld\n", max_files);
    printf("Size of pipe (circular buffer) in bytes: %d\n", pipe_size);

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}

/* 
Sample Output:
$ ./a.out
Maximum number of files a process can open: 1024
Size of pipe (circular buffer) in bytes: 65536
*/

