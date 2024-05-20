#pragma once
#include <map>
#include <string>
#include <FileManager/FileReader.h>
#include "BadEnvFile.h"

class GetEnv{
    std::map<std::string, std::string> config;
public:
    GetEnv(){};
    void getenv();
    std::string env(const std::string &, std::string) const;
};