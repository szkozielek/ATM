#pragma once
#include <iostream>
namespace layout{
    class Layout{
    protected:
        std::ostream * const output;
    public:
        inline Layout(std::ostream * output): output(output) {}
        virtual void show() = 0;
    };

    template<typename T, typename... Args> 
    inline void show(std::ostream * output, Args... args){
        T layout(output, args...);
        layout.show();
    }
}


