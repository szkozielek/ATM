#pragma once
#include <string>
#include <fstream>
#include "FileNotFound.h"

class FileWriter
{
    std::fstream file;
    std::string path;

public:
    FileWriter(const std::string &, bool = true, bool = false);
    bool isEOF();
    bool isEmpty();
    template <typename T>
    FileWriter &operator<<(const T &var)
    {
        this->file << var;
        return *this;
    }
    ~FileWriter();
};