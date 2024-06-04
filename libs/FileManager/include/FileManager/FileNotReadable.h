#pragma once
#include <string>
#include <exception>

namespace except
{
    class FileNotReadable : public std::exception
    {
    protected:
        std::string message;
        FileNotReadable();
    public:
        FileNotReadable(const std::string &);
        virtual const char *what() const noexcept;
    };
}
