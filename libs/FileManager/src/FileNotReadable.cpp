#include "FileNotReadable.h"

except::FileNotReadable::FileNotReadable() 
{
}

except::FileNotReadable::FileNotReadable(const std::string & msg) 
{
    this->message = "Program couldn't read this file: " + msg;
}

const char *except::FileNotReadable::what() const noexcept
{
    return (this->message).c_str();
}