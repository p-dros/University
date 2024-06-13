#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>     // for close function
#include <netinet/in.h> // ipv4

#include <arpa/inet.h>  // for inet_ntoa function

#include <ctype.h>     // for isprint function

#define BUFFER_SIZE 32 

int main(int argc, char *argv[]) {
    const char *message = "Hello, world!\r\n";

    unsigned int port;
    unsigned char buf[BUFFER_SIZE];

    int server_socket;

    ssize_t bytes_count;

    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    socklen_t client_address_length = sizeof(client_address);

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    port = atoi(argv[1]);
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&client_address, 0, sizeof(client_address));
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listens on address %s and port %d\n", 
           inet_ntoa(server_address.sin_addr), 
           ntohs(server_address.sin_port));

    while (1) {
        bytes_count = recvfrom(server_socket, (char *)buf, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *) &client_address, &client_address_length);
        if (bytes_count == -1) {
            perror("recvfrom");
            close(server_socket);
            exit(EXIT_FAILURE);
        } 


        printf("New datagram from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        printf("Bytes count: %ld\n", bytes_count);

        for (ssize_t i = 0; i < bytes_count; i++) {
            if (isprint(buf[i]) || buf[i] == '\n' || buf[i] == '\r' || buf[i] == '\t') {
                putchar(buf[i]);
            }
        }
        putchar('\n');

        sendto(server_socket, message, strlen(message), MSG_CONFIRM, (const struct sockaddr *) &client_address, client_address_length);

        memset(buf, 0, sizeof(buf)); // Clear buffer
    }

    close(server_socket);

    return EXIT_SUCCESS;
}