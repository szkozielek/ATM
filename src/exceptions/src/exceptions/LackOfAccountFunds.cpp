#include "LackOfAccountFunds.h"

except::LackOfAccountFunds::LackOfAccountFunds()
{
}

const char *except::LackOfAccountFunds::what() const noexcept
{
    return "Brak srodkow na koncie";
}