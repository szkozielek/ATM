#pragma once
#include <iostream>
#include <string>
#include <Menu/Colors.h>
#include "View.h"

template <typename T>
class MarkView : private View
{
    T value;
    std::string label;
    void render();
public:
    MarkView(std::ostream * const, const std::string &);
    void render(const T &);
};


template <typename T>
MarkView<T>::MarkView(std::ostream * const output, const std::string & label) : View(nullptr, output), label(label)
{

}

template <typename T>
void MarkView<T>::render()
{
    *this->output << colors::white << this->label << colors::yellow << this->value << colors::white << std::endl;
}

template <typename T>
void MarkView<T>::render(const T & value)
{
    this->value = value;
    this->render();
}