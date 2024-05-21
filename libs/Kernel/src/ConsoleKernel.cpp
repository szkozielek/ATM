#include "ConsoleKernel.h"

ConsoleKernel::ConsoleKernel(
    const int argc,
    const char **const argv,
    const GetEnv *const config,
    std::istream *const input,
    std::ostream *const output) : Kernel(argc, argv, config), input(input), output(output) {}