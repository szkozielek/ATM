#pragma once
#include <iostream>
#include <string>
#include <map>

#include <Kernel/ConsoleKernel.h>
#include <GetEnv/GetEnv.h>

#include <layout/Exit.h>
#include <controllers/StartController.h>

class App : protected ConsoleKernel
{
public:
    App(const int, const char **const, const GetEnv *const, std::istream *const, std::ostream *const);
    void run();
};