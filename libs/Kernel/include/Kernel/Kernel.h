#pragma once

class Kernel {
protected:
    int argc;
    char ** const argv;
    virtual void initArgs() = 0;
public:
    Kernel(int, char ** const);
    virtual void run() = 0;
};