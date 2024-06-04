#pragma once
#include <iostream>
#include <Menu/Colors.h>
#include "Layout.h"

namespace layout
{
    class Confirm : public Layout
    {
        std::string label;

    public:
        inline Confirm(std::ostream *output, const std::string &message) : Layout(output), label(message) {}
        inline void show()
        {
            *this->output << this->label << " (" << colors::yellow << "tak" << colors::white << "/" << colors::yellow << "nie" << colors::white << "): ";
        }
    };
}