#pragma once
#include <iostream>
#include <Menu/Colors.h>
#include <Menu/Menu.h>
#include "Layout.h"

namespace layout
{
    class Message : public Layout
    {
        std::string message;
        colors::color color;

    public:
        inline Message(std::ostream *output, const std::string &message, const colors::color &color) : Layout(output), message(message), color(color) {}
        inline void show()
        {
            *this->output << this->color;
            menu::line(*this->output, 70);
            *this->output << std::endl
                          << this->message << std::endl;
            menu::line(*this->output, 70);
            *this->output << std::endl
                          << colors::white << std::endl;
        }
    };
}