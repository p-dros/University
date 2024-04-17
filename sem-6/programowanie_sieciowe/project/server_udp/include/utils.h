#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

typedef struct {
    int total_count;
    int palindrome_count;
} WordStats;

bool is_palindrome(char *str);
WordStats count_palindromes(char *str);
void custom_print(char *str);

#endif  // UTILS_H