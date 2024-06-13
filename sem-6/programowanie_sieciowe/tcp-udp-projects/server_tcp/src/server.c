#include "server.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#include "logs.h"

int setup_tcp_socket(in_port_t port) {
    int server_fd;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(
            server_fd,
            (struct sockaddr *)&server_address,
            sizeof(server_address)
        ) == -1) {
        perror("bind");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) == -1) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf(
        "Server listens on address %s:%d\n\n",
        inet_ntoa(server_address.sin_addr),
        ntohs(server_address.sin_port)
    );

    return server_fd;
}

int accept_connection(int server_fd) {
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);

    int client_fd = accept(
        server_fd, (struct sockaddr *)&client_address, &client_address_len
    );

    if (client_fd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    log_verbose(
        "Accepted connection from address %s:%d. Desc: %i",
        inet_ntoa(client_address.sin_addr),
        ntohs(client_address.sin_port),
        client_fd
    );

    return client_fd;
}

ssize_t read_verbose(int fd, void *buf, size_t buf_size) {
    ssize_t bytes_read;
    if ((bytes_read = read(fd, buf, buf_size)) == -1) {
        log_perror("read");
    }

    return bytes_read;
}

ssize_t write_verbose(int fd, const void *buf, size_t buf_size) {
    ssize_t bytes_written;
    if ((bytes_written = write(fd, buf, buf_size)) == -1) {
        log_perror("write");
    }

    return bytes_written;
}
