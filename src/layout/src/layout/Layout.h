#pragma once

#include <iostream>

namespace layout
{
    class Layout
    {
    protected:
        std::istream *const input;
        std::ostream *const output;

    public:
        inline Layout(std::ostream *const output) : output(output), input(nullptr){}
        inline Layout(std::ostream *const output, std::istream *const input) : output(output), input(input) {}
        virtual void show() = 0;
    };

    template <typename T, typename... Args>
    inline void show(std::ostream *output, Args... args)
    {
        T layout(output, args...);
        layout.show();
    }
}
