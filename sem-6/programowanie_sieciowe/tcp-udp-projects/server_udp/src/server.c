#include "server.h"

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int setup_udp_socket(int port) {
    int socket_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socket_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY,
    };

    if (bind(
            socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)
        ) == -1) {
        perror("bind");
        close(socket_fd);
        exit(EXIT_FAILURE);
    };

    printf(
        "Server listens on address %s and port %d\n",
        inet_ntoa(server_address.sin_addr),
        ntohs(server_address.sin_port)
    );

    return socket_fd;
}

ssize_t receive_data(
    int socket_fd,
    char* buffer,
    size_t buffer_size,
    struct sockaddr_in* client_address,
    socklen_t* client_address_size
) {
    ssize_t bytes_count = recvfrom(
        socket_fd,
        buffer,
        buffer_size,
        MSG_WAITALL,
        (struct sockaddr*)client_address,
        client_address_size
    );

    printf(
        "Received message from %s:%d\n",
        inet_ntoa(client_address->sin_addr),
        ntohs(client_address->sin_port)
    );

    printf("Received %ld bytes\n", bytes_count);

    return bytes_count;
}

void send_data(
    int socket_fd,
    char* str,
    struct sockaddr_in* client_address,
    socklen_t client_address_size
) {
    sendto(
        socket_fd,
        str,
        strlen(str),
        0,
        (struct sockaddr*)client_address,
        client_address_size
    );
}