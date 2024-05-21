#include "Colors.h"

bool colors::useColors = false;

std::ostream &operator<<(std::ostream &out, const colors::color &myColor)
{
    if (colors::useColors == true)
    {
        return out << colors::dict[myColor];
    }
    return out;
}