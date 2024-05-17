#pragma once
#include <exception>
namespace except{
    class TooLargeAmount: public std::exception{
    public:
        virtual const char* what() const noexcept;
    };
}