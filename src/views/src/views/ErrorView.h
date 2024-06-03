#pragma once
#include <iostream>
#include <string>
#include <Menu/Colors.h>
#include <Menu/Menu.h>
#include "View.h"

class ErrorView : private View
{
    std::string error;

public:
    ErrorView(std::ostream *const, const std::string &);
    void render();
};