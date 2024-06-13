#include "palindrome.h"

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(char* buf, int buf_size) {
  for (int i = 0; i < buf_size / 2; i++) {
    if (tolower(buf[i]) != tolower(buf[buf_size - i - 1])) {
      return false;
    }
  }

  return true;
}
