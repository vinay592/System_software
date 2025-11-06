/*
================================================================================
Name : 33_client
Author : Vinay V Bhandare
Description : Client program to communicate with server over TCP socket
Date : 29th Sept 2025
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main()
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "Hello Server";
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        perror("Invalid address / Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent to server\n");

    read(sock, buffer, 1024);
    printf("Message from server: %s\n", buffer);

    close(sock);

    return 0;
}

/*
Output (Client):
$ ./client
Hello message sent to server
Message from server: Hello from server
*/

