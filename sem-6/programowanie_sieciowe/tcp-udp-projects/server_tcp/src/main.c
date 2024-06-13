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
#include "utils.h"

#define PORT 2020
#define MAX_BUFFOR_LENGTH 1024

void send_error_message(int client_fd) {
  char* error_message = "ERROR\r\n";
  log_verbose("Sending: %s", error_message);

  write_verbose(client_fd, error_message, strlen(error_message));
}

void send_success_message(int client_fd, WordStats* stats) {
  char message[MAX_BUFFOR_LENGTH];
  snprintf(message,
           MAX_BUFFOR_LENGTH,
           "%d/%d\r\n",
           stats->palindrome_count,
           stats->total_count);
  log_verbose("Sending: %s", message);
  write_verbose(client_fd, message, strlen(message));
}

typedef enum State {
  INIT,
  LETTER,
  SPACE,
  CR,
  ERROR,
  ERROR_CR,
} State;

void handle_client(int client_fd) {
  char buf[MAX_BUFFOR_LENGTH];
  char word[MAX_BUFFOR_LENGTH];
  int bytes_count;
  int word_size = 0;

  WordStats line_stats = {
      .palindrome_count = 0,
      .total_count = 0,
  };

  State state = INIT;

  while ((bytes_count = read_verbose(client_fd, buf, MAX_BUFFOR_LENGTH)) > 0) {
    if (word == NULL) {
      close(client_fd);
      return;
    }

    for (char* b = buf; b < buf + bytes_count; b++) {
      // UNNATURAL BEHAVIOUR\r\n
      if (!is_ascii(*b)) {
        close(client_fd);
        return;
      }

      switch (state) {
        case INIT:
          line_stats.palindrome_count = 0;
          line_stats.total_count = 0;

          if (isalpha(*b) != 0) {
            state = LETTER;
            word[0] = *b;
            word_size = 1;
          } else if (*b == '\r') {
            state = CR;
          } else {
            state = ERROR;
          }
          break;

        case LETTER:
          if (isalpha(*b) != 0) {
            state = LETTER;
            word[word_size] = *b;
            word_size++;
            break;
          }

          if (*b == ' ') {
            state = SPACE;
          } else if (*b == '\r') {
            state = CR;
          } else {
            state = ERROR;
            break;
          }

          if (is_palindrome(word, word_size)) {
            line_stats.palindrome_count++;
          }

          line_stats.total_count++;

          break;
        case SPACE:
          if (isalpha(*b) != 0) {
            state = LETTER;
            word_size = 1;
            word[0] = *b;
          } else {
            state = ERROR;
            b--;
          }

          break;
        case CR:
          if (*b == '\n') {
            send_success_message(client_fd, &line_stats);

            state = INIT;
          } else {
            state = ERROR;
            b--;
          }

          break;
        case ERROR:
          if (*b == '\r') {
            state = ERROR_CR;
          }

          break;
        case ERROR_CR:
          if (*b == '\n') {
            state = INIT;
            send_error_message(client_fd);
          } else if (*b != '\r') {
            state = ERROR;
          }

          break;
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