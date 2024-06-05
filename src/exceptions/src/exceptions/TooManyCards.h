#pragma once
#include <stdexcept>

namespace except
{
    class TooManyCards : public std::out_of_range
    {
    public:
        TooManyCards();
    };
}