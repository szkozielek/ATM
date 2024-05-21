#include "FileNotReadable.h"

except::FileNotReadable::FileNotReadable(char *filename) : filename(filename) {}

const char *except::FileNotReadable::what() const noexcept
{
    return strcat((char *)"Program couldn't read this file: ", this->filename);
}