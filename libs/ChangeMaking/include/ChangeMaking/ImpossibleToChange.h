#pragma once
#include <exception>
namespace except
{
    class ImpossibleToChange : public std::exception
    {
    public:
        virtual const char *what() const noexcept;
    };
}