#pragma once
#include <iostream>
#include <string>

namespace menu
{
    extern bool useConsoleClear;
    extern bool useConsoleHide;
    std::ostream &clearScreen(std::ostream &);
    std::ostream &drawSign(std::ostream &, unsigned short, char);
    std::ostream &boldLine(std::ostream &, unsigned short);
    std::ostream &line(std::ostream &, unsigned short);
    std::ostream &hideText(std::ostream &);
    std::ostream &showText(std::ostream &);
}