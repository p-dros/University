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
    unsigned int port;
    
    int client_socket;
    
    ssize_t bytes_count;
    
    const char *server_ip;
    const char *message = "";
    unsigned char buf[BUFFER_SIZE];

    struct sockaddr_in server_address;

    socklen_t server_address_length = sizeof(server_address);

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip_address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server_ip = argv[1];
    port = atoi(argv[2]);

    client_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if(client_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(port);


    if (sendto(client_socket, message, strlen(message), MSG_CONFIRM, (const struct sockaddr *) &server_address,
        sizeof(server_address)) == -1) {
        perror("sendto");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    printf("Datagram sent to server\n");
    

    bytes_count = recvfrom(client_socket, (char *) buf, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *) &server_address,
        &server_address_length);
    if (bytes_count == -1) {
        perror("recvfrom");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    for (ssize_t i = 0; i < bytes_count; i++) {
        if (isprint(buf[i]) || buf[i] == '\n' || buf[i] == '\r' || buf[i] == '\t') {
            putchar(buf[i]);
        }
    }
    putchar('\n');

    close(client_socket);

    return EXIT_SUCCESS;
}