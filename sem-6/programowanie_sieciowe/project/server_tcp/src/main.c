#include <ctype.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "logs.h"
#include "palindrome.h"
#include "server.h"

#define PORT               3020
#define MAX_BUFFOR_LENGTH  65507
#define MAX_REQUEST_LENGTH 1024

typedef struct {
    bool during_proccess;
    WordStats stats;
    bool last_carriage_return;
    bool last_space;
} LineState;

void set_default(LineState* state) {
    state->last_carriage_return = false;
    state->stats.palindrome_count = 0;
    state->stats.total_count = 0;
    state->last_space = false;
}

void send_error_message(int client_fd, LineState* state) {
    char* error_message = "ERROR\r\n";

    write_verbose(client_fd, error_message, strlen(error_message));
    set_default(state);
}

void send_success_message(int client_fd, LineState* state) {
    char message[MAX_REQUEST_LENGTH];
    snprintf(
        message,
        MAX_REQUEST_LENGTH,
        "%d/%d\r\n",
        state->stats.palindrome_count,
        state->stats.total_count
    );
    write_verbose(client_fd, message, strlen(message));
    set_default(state);
}

void handle_client(int client_fd) {
    char buf[MAX_BUFFOR_LENGTH];
    int bytes_count;

    LineState line_state;
    set_default(&line_state);

    while ((bytes_count = read_verbose(client_fd, buf, MAX_BUFFOR_LENGTH)) > 0
    ) {
        for (int i = 0; i < bytes_count; i++) {
            if (buf[i] == '\n') {
                if (line_state.last_carriage_return) {
                    send_success_message(client_fd, &line_state);
                } else {
                    send_error_message(client_fd, &line_state);
                }
            } else if (buf[i] == '\r') {
                line_state.last_carriage_return = true;
            } else if (buf[i] == ' ' && line_state.last_space) {
                send_error_message(client_fd, &line_state);
            } else if (buf[i] == ' ') {
                line_state.last_space = true;
            }
        }
    }
}

int main(int argc, char** argv) {
    int server_fd = setup_tcp_socket(PORT);

    if (signal(SIGCHLD, SIG_IGN) == SIG_ERR) {
        log_perror("signal");
        exit(EXIT_FAILURE);
    }

    while (true) {
        int client_fd = accept_connection(server_fd);

        pid_t pid = fork();

        if (pid == -1) {
            log_perror("fork");
            continue;
        } else if (pid == 0) {
            close(server_fd);

            handle_client(client_fd);

            close(client_fd);
            exit(EXIT_SUCCESS);
        }

        close(client_fd);
    }

    close(server_fd);
    return 0;
}