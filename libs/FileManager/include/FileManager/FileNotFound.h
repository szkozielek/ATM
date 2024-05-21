#pragma once
#include <cstring>
#include "FileNotReadable.h"
namespace except
{
    class FileNotFound : public FileNotReadable
    {
        char *filename;

    public:
        FileNotFound(char *);
        virtual const char *what() const noexcept;
    };
}
