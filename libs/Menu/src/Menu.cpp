#include "Menu.h"

bool menu::useConsoleClear = false;

std::ostream & menu::clearScreen(std::ostream& out){
    if(menu::useConsoleClear){
        out << "\x1b[2J";
    }
    return out;
}

