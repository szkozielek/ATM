#pragma once
#include <map>
#include <string>
#include <FileManager/FileReader.h>
#include "BadEnvFile.h"

class GetEnv{
    std::map<std::string, std::string> config;
protected:
    void getenv();
    std::string env(const std::string &, std::string);
    GetEnv(){};
};