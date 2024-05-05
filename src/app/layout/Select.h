#pragma once
#include <map>
#include <iostream>
#include <Menu/Colors.h>
#include "Layout.h"


namespace layout{
    class Select : public Layout{
        std::map<std::string, std::string> options;
    public:
        Select(std::ostream * output, std::map<std::string, std::string> options): Layout(output), options(options){}
        void show(){
            std::map<std::string, std::string>::iterator iter;
            for(iter = this->options.begin(); iter != this->options.end(); ++iter){
                this->output->width(30);
                *this->output << iter->second;
                *this->output << "\t[" << colors::yellow << iter->first << colors::white << "]" << std::endl;
            }
        }
    };
}
