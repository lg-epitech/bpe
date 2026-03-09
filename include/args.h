#ifndef ARGS_H_
    #define ARGS_H_
    #include <limits.h>
    #define DEFAULT_VOCABULARY_CAPACITY ULLONG_MAX

#define OPTIONAL_ARGS \
    OPTIONAL_STRING_ARG(input, "", "-i", "input", "The input to encode.") \
    OPTIONAL_ULONG_LONG_ARG(capacity, 1000, "-c", "capacity", "The vocabulary capacity")

#define BOOLEAN_ARGS \
    BOOLEAN_ARG(use_stdin, "-s", "Use stdin as input.") \
    BOOLEAN_ARG(help, "--help", "Show program usage.")

#include "./easyargs.h"

#endif /* !ARGS_H_ */
