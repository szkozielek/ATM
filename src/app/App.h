#pragma once
#include <iostream>
#include <string>
#include <map>
#include <Menu/Colors.h>
#include <Menu/Menu.h>
#include <GetEnv/GetEnv.h>
#include <Kernel/ConsoleKernel.h>
#include "layout/Index.h"
#include "layout/Exit.h"
#include "layout/Select.h"

class App: public ConsoleKernel, protected GetEnv{
    std::map<std::string, std::string> config;
    void initArgs();
public:
    App(std::istream *, std::ostream *);
    void run();
};