#pragma once
#include <iostream>
#include <string>
#include <map>
#include <GetEnv/GetEnv.h>
#include <Kernel/ConsoleKernel.h>
#include <controllers/StartController.h>
#include <layout/Exit.h>

class App: protected ConsoleKernel{
public:
    App(const int, const char** const, const GetEnv * const, std::istream * const, std::ostream * const);
    void run();
};