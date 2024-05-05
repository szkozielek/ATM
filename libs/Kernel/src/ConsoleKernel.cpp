#include "ConsoleKernel.h"

ConsoleKernel::ConsoleKernel(const int argc, const char** const argv, std::istream * const input, std::ostream * const output) : Kernel(argc, argv), input(input), output(output){}