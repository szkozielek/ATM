#pragma once
#include <iostream>
#include <GetEnv/GetEnv.h>

class Controller{
protected:
    const GetEnv * const config;
    std::istream * const input;
    std::ostream * const output;
public:
    Controller(const GetEnv * const, std::istream * const, std::ostream * const);
};