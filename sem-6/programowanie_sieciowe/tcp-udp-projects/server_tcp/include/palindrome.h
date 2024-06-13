#ifndef PALINDROMES_H
#define PALINDROMES_H

#include <stdbool.h>

typedef struct {
  int total_count;
  int palindrome_count;
} WordStats;

bool is_palindrome(char* buf, int buf_size);

#endif  // PALINDROMES_H