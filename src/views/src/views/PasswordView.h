#pragma once
#include <iostream>
#include <string>
#include <Menu/Menu.h>
#include "View.h"

class PasswordView : public View
{
    std::string label;

public:
    PasswordView(std::istream *const, std::ostream *const, const std::string &);
    void render();
    std::string get();
};