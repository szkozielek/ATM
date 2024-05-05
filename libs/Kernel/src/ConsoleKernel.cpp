#include "ConsoleKernel.h"

ConsoleKernel::ConsoleKernel(int argc, char** const argv, std::istream * input, std::ostream * output) : Kernel(argc, argv), input(input), output(output){}