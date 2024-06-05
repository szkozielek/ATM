#include "LoginInUse.h"

except::LoginInUse::LoginInUse()
{
}

const char *except::LoginInUse::what() const noexcept
{
    return "Podany login jest juz w uzyciu";
}