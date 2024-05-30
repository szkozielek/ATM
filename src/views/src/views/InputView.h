#pragma once
#include <iostream>
#include <string>
#include <Menu/Colors.h>
#include "View.h"

template <typename T>
class InputView : private View
{
    std::string label;
public:
    InputView(std::istream * const, std::ostream * const, const std::string &);
    void render();
    T get();
};

template <typename T>
InputView<T>::InputView(std::istream * const input, std::ostream * const output, const std::string &label) : View(input, output), label(label)
{

}

template <typename T>
void InputView<T>::render(){
    *this->output << colors::white << label << colors::yellow;
}

template <typename T>
T InputView<T>::get(){
    T toGet;
    *this->input >> toGet;
    *this->output << colors::white;
    return toGet;
}