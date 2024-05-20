#pragma once
#include <iostream>
#include <Menu/Menu.h>
#include <Menu/Colors.h>
#include "Layout.h"


namespace layout{
    class Exit: public Layout{
    public:
        inline Exit(std::ostream * output) : Layout(output) {}
        inline void show(){
            menu::clearScreen(*this->output);
            *this->output << colors::green << "~~bye" << std::endl << std::endl << std::endl << std::endl << colors::white;
        }
    };
}