#pragma once
#include <iostream>
#include <string>
#include <map>
#include <Menu/Colors.h>
#include <Menu/Menu.h>
#include <GetEnv/GetEnv.h>
#include <Kernel/ConsoleKernel.h>
#include <SmartString/SmartString.h>
#include "layout/Index.h"
#include "layout/Exit.h"
#include "layout/Select.h"
#include "layout/ValidateError.h"
#include "controllers/BankAccountController.h"
#include "controllers/BankAccountController.cpp"

class App: public ConsoleKernel, protected GetEnv{
    std::map<std::string, std::string> config;
    void initArgs();
public:
    App(const int argc, const char** const argv, std::istream * const, std::ostream * const);
    void run();
};