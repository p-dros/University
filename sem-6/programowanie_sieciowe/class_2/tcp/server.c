#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>     // for close function
#include <netinet/in.h> // ipv4

#include <arpa/inet.h>  // for inet_ntoa function

#define BUFFER_SIZE 32

int main(int argc, char *argv[]) {
    unsigned int port;
    unsigned char buf[BUFFER_SIZE];
    int client_socket;
    int server_socket;
    struct sockaddr_in server_address;

    struct sockaddr_in client_address;
    socklen_t client_addr_len = sizeof(client_address);

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    port = atoi(argv[1]);
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 10) == -1) {
        perror("listen");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listens on address %s and port %d\n",
           inet_ntoa(server_address.sin_addr),
           ntohs(server_address.sin_port));

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_addr_len);
        if (client_socket == -1) {
            perror("accept");
            close(server_socket);
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n",
               inet_ntoa(client_address.sin_addr),
               ntohs(client_address.sin_port));

        const char *message = "Hello, world!\r\n";
        memcpy(buf, message, strlen(message));
        if (write(client_socket, buf, strlen(message)) == -1) {
            perror("write");
            close(server_socket);
            close(client_socket);
            exit(EXIT_FAILURE);
        }

        printf("Message sent\n\n");

        close(client_socket);
    }

    close(server_socket);

    return EXIT_SUCCESS;
}