#pragma once
#include <iostream>
#include <Menu/Colors.h>
#include "Layout.h"

namespace layout
{
    class ValidateError : public Layout
    {
        std::string errorMessage;

    public:
        inline ValidateError(std::ostream *output, const std::string &message) : Layout(output), errorMessage(message) {}
        inline void show()
        {
            *this->output << colors::red << "* " << this->errorMessage << colors::white << std::endl;
        }
    };
}
