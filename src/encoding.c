#include "../include/bpe.h"
#include "../include/vocabulary.h"

void load_input_vocabulary(vocabulary_t *voc, char *input) {
    while (*input != '\0') {
        char *one = malloc(2);
        one[0] = *input;
        one[1] = '\0';

        if (vocabulary_has(voc, one)) {
            free(one);
        } else {
            vocabulary_insert(voc, one);
        }

        ++input;
    }
}

void encode(args_t *args, char *input) {
    vocabulary_t *voc = vocabulary_init(args->capacity);

    load_input_vocabulary(voc, input);

    vocabulary_print(voc);

    vocabulary_destroy(voc);
}
