#include "FileNotFound.h"

except::FileNotFound::FileNotFound(const std::string &msg) : FileNotReadable() 
{
    this->message = "File not found: " + msg;
}

const char *except::FileNotFound::what() const noexcept
{
    return (this->message).c_str();
}