#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>
#include <sys/types.h>

int setup_udp_socket(int port);
ssize_t receive_data(
    int socket_fd,
    char* buffer,
    size_t buffer_size,
    struct sockaddr_in* client_address,
    socklen_t* client_address_size
);
void send_data(
    int socket_fd,
    char* str,
    struct sockaddr_in* client_address,
    socklen_t client_address_size
);

#endif  // SERVER_H
