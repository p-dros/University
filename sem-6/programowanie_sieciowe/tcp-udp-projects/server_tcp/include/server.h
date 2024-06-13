#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>

int setup_tcp_socket(in_port_t port);
int accept_connection(int server_fd);
ssize_t read_verbose(int fd, void *buf, size_t buf_size);
ssize_t write_verbose(int fd, const void *buf, size_t buf_size);

#endif  // SERVER_H
