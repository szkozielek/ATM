#pragma once
#include <iostream>
namespace layout{
    class Layout{
    protected:
        std::ostream * const output;
    public:
        Layout(std::ostream * output): output(output) {}
        virtual void show() = 0;
    };
}
