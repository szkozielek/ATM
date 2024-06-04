#pragma once
#include <string>
#include "FileNotReadable.h"
namespace except
{
    class FileNotFound : public FileNotReadable
    {
    public:
        FileNotFound(const std::string &);
        virtual const char *what() const noexcept;
    };
}
