#include "palindrome.h"

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - i - 1])) {
            return false;
        }
    }

    return true;
}

WordStats count_palindromes(char *str) {
    WordStats stats = {0, 0};
    char *word = strtok(str, " ");

    while (word != NULL) {
        stats.total_count++;

        if (is_palindrome(word)) {
            stats.palindrome_count++;
        }

        word = strtok(NULL, " ");
    }

    return stats;
}