#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <FileReader\FileReader.h>
#include <Menu\Colors.h>
#include <Menu\Menu.h>
#include "exceptions/BadEnvFile.h"
#include "layout/Index.h"
#include "layout/Exit.h"

class App{
    std::map<std::string, std::string> config;
    std::istream * const input;
    std::ostream * const output;
    void initArgs();
    void getenv();
    std::string env(const std::string &, std::string);
public:
    App(std::istream *, std::ostream *);
    void run();
};