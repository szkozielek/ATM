#pragma once
#include <GetEnv/GetEnv.h>
class Kernel {
protected:
    const int argc;
    const char ** const argv;
    const GetEnv * const config;
public:
    Kernel(const int, const char ** const, const GetEnv * const);
    virtual void run() = 0;
};