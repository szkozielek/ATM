#pragma once
#include <iostream>
#include <string>

namespace menu
{
    extern bool useConsoleClear;
    std::ostream &clearScreen(std::ostream &);
    std::ostream &drawSign(std::ostream &, unsigned short, char);
    std::ostream &boldLine(std::ostream &, unsigned short);
    std::ostream &line(std::ostream &, unsigned short);
}