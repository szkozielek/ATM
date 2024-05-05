#pragma once

class Kernel {
protected:
    const int argc;
    const char ** const argv;
    virtual void initArgs() = 0;
public:
    Kernel(const int, const char ** const);
    virtual void run() = 0;
};