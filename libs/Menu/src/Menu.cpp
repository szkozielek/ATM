#include "Menu.h"

bool menu::useConsoleClear = false;
bool menu::useConsoleHide = false;

std::ostream &menu::clearScreen(std::ostream &out)
{
    if (menu::useConsoleClear)
    {
        out << "\x1b[2J";
    }
    return out;
}

std::ostream &menu::drawSign(std::ostream &out, unsigned short length, char sign)
{
    out.fill(sign);
    out.width(length);
    out << "";
    out.fill(' ');
    return out;
}

std::ostream &menu::boldLine(std::ostream &out, unsigned short length)
{
    return menu::drawSign(out, length, '#');
}

std::ostream &menu::line(std::ostream &out, unsigned short length)
{
    return menu::drawSign(out, length, '-');
}

std::ostream & menu::hideText(std::ostream &out)
{
    if (menu::useConsoleHide)
    {
        out << "\x1B[8m";
    }
    return out;
}
std::ostream & menu::showText(std::ostream &out)
{
    if (menu::useConsoleHide)
    {
        out << "\x1B[28m";
    }
    return out;
}
