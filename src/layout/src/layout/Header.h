#pragma once
#include <iostream>
#include <Menu/Colors.h>
#include <Menu/Menu.h>
#include "Layout.h"

namespace layout
{
    class Header : public Layout
    {
        std::string label;

    public:
        inline Header(std::ostream *output, const std::string &label) : Layout(output), label(label) {}
        inline void show()
        {
            *this->output << colors::cyan;
            menu::line(*this->output, 40) << std::endl;
            menu::drawSign(*this->output, 20 - (this->label.size() / 2) - (this->label.size() % 2), ' ');
            *this->output << this->label << std::endl;
            menu::line(*this->output, 40) << colors::white << std::endl
                                          << std::endl;
        }
    };
}