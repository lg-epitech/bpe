#include "../include/bpe.h"
#include "../include/vocabulary.h"

#include <stdio.h>

void encode(args_t *args, char *input) {
    vocabulary_t *voc = vocabulary_init(args->capacity);

    printf("%s\n", input);

    vocabulary_destroy(voc);
}
