#include "BadCredentials.h"

except::BadCredentials::BadCredentials()
{
}

const char *except::BadCredentials::what() const noexcept
{
    return "Nieprawidlowe dane.";
}