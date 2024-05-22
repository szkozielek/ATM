#pragma once
#include <iostream>
#include <string>

#include "Layout.h"


namespace layout{
    class Password : public Layout
    {
        std::string *const password;
    public:
        inline Password(std::ostream *const output, std::string *const password) : Layout(output), password(password) {}
        inline void show()
        {   
            char prev = this->output->fill('*');
            this->output->width(this->password->size());
            *this->output << "" << std::endl;
            this->output->fill(prev);
        }
    };
}