#include "../include/bpe.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

char *read_stdin() {
    size_t capacity = getpagesize();
    size_t size = 0;
    char *buffer = malloc(capacity);

    if (!buffer) {
        return NULL;
    }

    size_t bytes_read;
    while ((bytes_read = fread(buffer + size, 1, capacity - size, stdin)) > 0) {
        size += bytes_read;

        if (size == capacity) {
            if (capacity > SIZE_MAX / 2) {
                free(buffer);
                return NULL;
            }

            capacity *= 2;
            char *new_buffer = realloc(buffer, capacity + 1);

            if (!new_buffer) {
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }
    }

    if (ferror(stdin)) {
        free(buffer);
        return NULL;
    }

    buffer[size] = '\0';
    return buffer;
}
