#pragma once
#include <iostream>
#include <string>
#include <map>

namespace colors
{
    extern bool useColors;
    enum color
    {
        white,
        red,
        green,
        yellow,
        cyan
    };
    static std::map<colors::color, std::string> dict = {
        {colors::white, "\x1b[0m"},
        {colors::red, "\x1b[31m"},
        {colors::green, "\x1b[32m"},
        {colors::yellow, "\x1b[93m"},
        {colors::cyan, "\x1b[36m"}};
}
std::ostream &operator<<(std::ostream &, const colors::color &);