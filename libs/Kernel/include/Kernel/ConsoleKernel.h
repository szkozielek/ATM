#pragma once
#include <iostream>
#include "Kernel.h"

class ConsoleKernel: public Kernel{
    protected:
        std::istream * const input;
        std::ostream * const output;
    public:
        ConsoleKernel(int, char** const, std::istream *, std::ostream *);
};