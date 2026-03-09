#include "../include/vocabulary.h"
#include <unistd.h>
#include <string.h>
#include <inttypes.h>

#define OPTIONAL_ARGS \
    OPTIONAL_STRING_ARG(arg_input, "", "-i", "input", "The input to encode.") \
    OPTIONAL_ULONG_LONG_ARG(capacity, DEFAULT_VOCABULARY_CAPACITY, "-c", "capacity", "The vocabulary capacity")

#define BOOLEAN_ARGS \
    BOOLEAN_ARG(use_stdin, "-s", "Use stdin as input.") \
    BOOLEAN_ARG(help, "--help", "Show program usage.")

#include "../include/easyargs.h"

int main(int argc, char **argv) {
    args_t args = make_default_args();

    if (!parse_args(argc, argv, &args) || args.help) {
        print_help(argv[0]);
        return 1;
    }

    vocabulary_t *voc = vocabulary_init(getpagesize());

    vocabulary_print(voc);

    vocabulary_insert(voc, strdup("a"));
    vocabulary_insert(voc, strdup("b"));
    vocabulary_insert(voc, strdup("c"));
    vocabulary_insert(voc, strdup("d"));
    vocabulary_insert(voc, strdup("e"));
    vocabulary_insert(voc, strdup("f"));
    vocabulary_insert(voc, strdup("g"));
    vocabulary_insert(voc, strdup("h"));
    vocabulary_insert(voc, strdup("i"));
    vocabulary_insert(voc, strdup("j"));
    vocabulary_insert(voc, strdup("k"));
    vocabulary_insert(voc, strdup("l"));
    vocabulary_insert(voc, strdup("m"));
    vocabulary_insert(voc, strdup("n"));
    vocabulary_insert(voc, strdup("o"));
    vocabulary_insert(voc, strdup("p"));
    vocabulary_insert(voc, strdup("q"));
    vocabulary_insert(voc, strdup("r"));
    vocabulary_insert(voc, strdup("s"));
    vocabulary_insert(voc, strdup("t"));
    vocabulary_insert(voc, strdup("u"));
    vocabulary_insert(voc, strdup("v"));
    vocabulary_insert(voc, strdup("w"));
    vocabulary_insert(voc, strdup("x"));
    vocabulary_insert(voc, strdup("y"));
    vocabulary_insert(voc, strdup("z"));

    vocabulary_print(voc);

    vocabulary_destroy(voc);

    return 0;
}
