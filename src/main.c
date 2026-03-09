#include "../include/bpe.h"
#include <unistd.h>
#include <inttypes.h>
#include "../include/args.h"

int main(int argc, char **argv) {
    args_t args = make_default_args();

    if (!parse_args(argc, argv, &args) || args.help) {
        print_help(argv[0]);
        return 1;
    }

    if (args.use_stdin) {
        encode(&args, read_stdin());
    } else if (strlen(args.input) != 0) {
        encode(&args, args.input);
    } else {
        print_help(argv[0]);
        return 1;
    }

    return 0;
}
