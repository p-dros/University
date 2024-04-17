#ifndef PALINDROMES_H
#define PALINDROMES_H

#include <stdbool.h>

typedef struct {
    int total_count;
    int palindrome_count;
} WordStats;

bool is_palindrome(char *str);

WordStats count_palindromes(char *str);

#endif  // PALINDROMES_H