#pragma once
#include <iostream>
#include "Kernel.h"

class ConsoleKernel: public Kernel{
    protected:
        std::istream * const input;
        std::ostream * const output;
    public:
        ConsoleKernel(const int, const char** const, std::istream * const, std::ostream * const);
};