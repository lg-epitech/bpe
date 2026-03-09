#ifndef VOCABULARY_H_
    #define VOCABULARY_H_
    #include <stdint.h>

typedef struct {
    uint64_t capacity;
    uint64_t size;
    char **entries; // For now considering ascii only (a character a byte)
} vocabulary_t;

// Returns a heap allocated structure, destroy much be called for memory release
vocabulary_t *vocabulary_init(uint64_t capacity);

void vocabulary_destroy(vocabulary_t *voc);

// Takes ownership of the entry
uint64_t vocabulary_insert(vocabulary_t *voc, char *entry);

#endif /* !VOCABULARY_H_ */
