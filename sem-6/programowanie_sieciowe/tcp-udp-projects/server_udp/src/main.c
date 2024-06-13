#include <arpa/inet.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "server.h"
#include "utils.h"

#define PORT 2020
#define MAX_BUFFOR_LENGTH 65507
#define MAX_WORD_LENGTH 1024

typedef enum {
  NO_ENDING,
  LF_ENDING,
  CRLF_ENDING,
} LineEnding;

typedef struct {
  LineEnding line_ending;
} RequestConfig;

int preprocess_request(char* buffer, int buffer_len, RequestConfig* config) {
  if (buffer_len > MAX_WORD_LENGTH) {
    return -1;
  }

  if (buffer[buffer_len - 1] == '\n' && buffer[buffer_len - 2] == '\r') {
    config->line_ending = CRLF_ENDING;
    buffer_len -= 2;
  } else if (buffer[buffer_len - 1] == '\n') {
    config->line_ending = LF_ENDING;
    buffer_len--;
  } else {
    config->line_ending = NO_ENDING;
  }

  for (int i = 0; i < buffer_len; i++) {
    if (isalpha(buffer[i]) == 0 && buffer[i] != ' ') {
      return -1;
    }

    if (i != buffer_len - 1 && buffer[i] == ' ' && buffer[i + 1] == ' ') {
      return -1;
    }
  }

  if (buffer[0] == ' ' || buffer[buffer_len - 1] == ' ') {
    return -1;
  }

  buffer[buffer_len] = '\0';

  return 0;
}

void set_error_message(char* response) {
  snprintf(response, MAX_WORD_LENGTH, "ERROR");
}

void set_response_message(char* response, WordStats* stats) {
  snprintf(response, MAX_WORD_LENGTH, "%d/%d", stats->palindrome_count,
           stats->total_count);
}

void proccess_request(char* buffer, int buffer_len, char* response) {
  RequestConfig request_config;

  int preprocess_result =
      preprocess_request(buffer, buffer_len, &request_config);

  if (preprocess_result == -1) {
    set_error_message(response);
  } else {
    WordStats stats = count_palindromes(buffer);
    set_response_message(response, &stats);
  }

  switch (request_config.line_ending) {
    case LF_ENDING:
      strcat(response, "\r\n");
      break;
    case CRLF_ENDING:
      strcat(response, "\r\n");
      break;
    case NO_ENDING:
      break;
    default:
      break;
  }
}

int main(int argc, char* argv[]) {
  int socket_fd = setup_udp_socket(PORT);

  while (true) {
    char buffer[MAX_BUFFOR_LENGTH];
    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);

    ssize_t bytes_count = receive_data(socket_fd, buffer, MAX_BUFFOR_LENGTH,
                                       &client_address, &client_address_size);

    if (bytes_count == -1) {
      continue;
    }

    char response[MAX_WORD_LENGTH];
    proccess_request(buffer, bytes_count, response);

    send_data(socket_fd, response, &client_address, client_address_size);
  }

  return 0;
}
