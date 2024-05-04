#pragma once
#include <iostream>
#include <Menu/Menu.h>
#include <Menu/Colors.h>
#include "Layout.h"


namespace layout{
    class Index: public Layout{
    public:
        Index(std::ostream * output) : Layout(output) {}
        void show(){
            *this->output << colors::yellow;
            menu::boldLine(*this->output, 40) << std::endl;
            menu::line(*this->output, 40) << std::endl;
            menu::drawSign(*this->output, 12, ' ');
            *this->output << colors::red << "B A N K O M A T" << colors::yellow << std::endl; 
            menu::line(*this->output, 40) << std::endl;
            menu::boldLine(*this->output, 40) << std::endl;
            *this->output << colors::white << std::endl << std::endl << std::endl;
            *this->output << "Nacisnij dowolny klawisz, aby rozpoczac..." << std::endl << std::endl;
        }
    };
}