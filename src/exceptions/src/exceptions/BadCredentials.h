#pragma once
#include <exception>

namespace except
{
    class BadCredentials : std::exception
    {
    public:
        BadCredentials();
        virtual const char *what() const noexcept;
    };
}
