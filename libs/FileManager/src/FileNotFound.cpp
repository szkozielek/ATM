#include "FileNotFound.h"

except::FileNotFound::FileNotFound(char *filename) : FileNotReadable(filename) {}

const char *except::FileNotFound::what() const noexcept
{
    return strcat((char *)"File not found: ", this->filename);
}