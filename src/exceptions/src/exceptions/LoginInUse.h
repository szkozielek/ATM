#pragma once
#include <exception>

namespace except
{
    class LoginInUse : std::exception
    {
    public:
        LoginInUse();
        virtual const char *what() const noexcept;
    };
}