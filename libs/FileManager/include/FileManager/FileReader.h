#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "FileNotFound.h"

class FileReader
{
    std::fstream file;
    std::string path;

public:
    FileReader(const std::string &);
    std::string getLastLine();
    bool isEOF();
    operator bool();
    template <typename T>
    FileReader &operator>>(T &var)
    {
        this->file >> var;
        return *this;
    }
    ~FileReader();
};