#include "utils.h"

#include <stdbool.h>
#include <stdio.h>

bool is_ascii(char character) {
  return character >= 0 && character <= 127;
}

void special_print(const char* str) {
  while (*str != '\0') {
    if (*str == '\n') {
      printf("\\n");
    } else if (*str == '\r') {
      printf("\\r");
    } else if (*str == ' ') {
      printf("<space>");
    } else {
      putchar(*str);
    }

    str++;
  }
}