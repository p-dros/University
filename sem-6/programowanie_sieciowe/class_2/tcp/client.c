#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>     // for close function
#include <netinet/in.h> // ipv4

#include <arpa/inet.h>  // for inet_ntoa function

#include <ctype.h>      // for isprint function

#define BUFFER_SIZE 32

int main(int argc, char *argv[]) {
    int client_socket;
    unsigned int port;
    struct sockaddr_in server_address;
    const char *server_ip;
    unsigned char buf[BUFFER_SIZE];
    ssize_t count;


    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip_address> <port>\n", argv[0]);
         exit(EXIT_FAILURE);
    }

    server_ip = argv[1];
    port = atoi(argv[2]);

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(port);

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("connect");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    count = read(client_socket, buf, BUFFER_SIZE);
    if (count == -1) {
        perror("read");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    for (ssize_t i = 0; i < count; i++) {
        if (isprint(buf[i]) || buf[i] == '\n' || buf[i] == '\r' || buf[i] == '\t') {
            putchar(buf[i]);
        }
    }
    putchar('\n');

    close(client_socket);

    return EXIT_SUCCESS;
}