#include <criterion/criterion.h>
#include "../include/vocabulary.h"
#include <string.h>

Test(vocabulary, init_sets_capacity_and_empty_size) {
    vocabulary_t *voc = vocabulary_init(16);

    cr_assert_eq(voc->capacity, 16);
    cr_assert_eq(voc->size, 0);

    vocabulary_destroy(voc);
}

Test(vocabulary, insert_increases_size) {
    vocabulary_t *voc = vocabulary_init(4);

    vocabulary_insert(voc, strdup("a"));
    cr_assert_eq(voc->size, 1);

    vocabulary_insert(voc, strdup("b"));
    cr_assert_eq(voc->size, 2);

    vocabulary_destroy(voc);
}

Test(vocabulary, insert_returns_index) {
    vocabulary_t *voc = vocabulary_init(4);

    uint64_t idx0 = vocabulary_insert(voc, strdup("hello"));
    uint64_t idx1 = vocabulary_insert(voc, strdup("world"));

    cr_assert_eq(idx0, 0);
    cr_assert_eq(idx1, 1);

    vocabulary_destroy(voc);
}

Test(vocabulary, insert_stores_entry) {
    vocabulary_t *voc = vocabulary_init(4);

    vocabulary_insert(voc, strdup("foo"));

    cr_assert_str_eq(voc->entries[0], "foo");

    vocabulary_destroy(voc);
}
