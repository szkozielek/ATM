#pragma once
#include <iostream>
#include <GetEnv/GetEnv.h>
#include "Kernel.h"

class ConsoleKernel: public Kernel{
    protected:
        std::istream * const input;
        std::ostream * const output;
    public:
        ConsoleKernel(const int, const char** const, const GetEnv * const, std::istream * const, std::ostream * const);
};