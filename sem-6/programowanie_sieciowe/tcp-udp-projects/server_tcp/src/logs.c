#define _POSIX_C_SOURCE 200809L

#include "logs.h"

#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void log_verbose(const char* format, ...) {
    char buf[BUFFER_SIZE];
    int len = 0;

    struct timespec date_unix;
    struct tm date;

    if (clock_gettime(CLOCK_REALTIME, &date_unix) == -1) {
        perror("clock_gettime");
        return;
    }
    if (localtime_r(&date_unix.tv_sec, &date) == NULL) {
        perror("localtime_r");
        return;
    }

    pid_t pid = getpid();

    len = snprintf(
        buf,
        BUFFER_SIZE,
        "%02i:%02i:%02i PID=%ji ",
        date.tm_hour,
        date.tm_min,
        date.tm_sec,
        (intmax_t)pid
    );

    if (len < 0) {
        return;
    }

    va_list args;
    va_start(args, format);
    int i = vsnprintf(buf + len, sizeof(buf) - len, format, args);
    va_end(args);
    if (i < 0) {
        return;
    }
    len += i;

    buf[len] = '\n';
    write(1, buf, len + 1);
}

void log_perror(const char* msg) {
    log_verbose("%s: %s", msg, strerror(errno));
}
