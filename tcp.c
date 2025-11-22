#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

int passive_server(int port, int queue)
{
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(port);
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_sockfd, (struct sockaddr *)&server_sockaddr, sizeof(server_sockaddr)) == -1)
    {
        perror("bind");
        exit(1);
    }
    if (listen(server_sockfd, queue) == -1)
    {
        perror("listen");
        exit(1);
    }
    printf("Listen to %d\n", port);
    return server_sockfd;
}
