#pragma once
#include <iostream>
#include <string>
#include <Menu/Colors.h>
#include "View.h"

class NewCardIDView : public View
{
    std::string cardID;

public:
    NewCardIDView(std::istream *const, std::ostream *const);
    void render();
    inline void setID(const std::string &cardID) { this->cardID = cardID; }
};