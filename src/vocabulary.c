#include "../include/vocabulary.h"
#include <stdlib.h>
#include <string.h>

vocabulary_t *vocabulary_init(uint64_t capacity) {
    vocabulary_t *voc = (vocabulary_t*)malloc(sizeof(vocabulary_t));

    voc->capacity = capacity;
    voc->size = 0;

    const uint64_t entries_size = sizeof(char *) * capacity;

    voc->entries = (char **)malloc(entries_size);
    memset(voc->entries, 0, entries_size);

    return voc;
}

void vocabulary_destroy(vocabulary_t *voc) {
    for (uint64_t i = 0; i < voc->size; ++i) {
        free(voc->entries[i]);
    }
    free(voc->entries);
    free(voc);
}

uint64_t vocabulary_insert(vocabulary_t *voc, char *entry) {
    uint64_t index = voc->size;

    if (index - 1 == voc->capacity) {
        return 0;
    }
    voc->entries[index] = entry;
    ++voc->size;

    return index;
}
