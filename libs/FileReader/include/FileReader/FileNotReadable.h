#pragma once
#include <cstring>
#include <exception>

namespace except{
    class FileNotReadable: public std::exception{
        char* filename;
    public:
        FileNotReadable(char *);
        virtual const char* what() const noexcept;
    };
}
