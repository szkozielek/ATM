#pragma once
#include <exception>

namespace except
{
    class LackOfAccountFunds : std::exception
    {
    public:
        LackOfAccountFunds();
        virtual const char *what() const noexcept;
    };
}