#pragma once
#include <iostream>
#include <string>
#include <Menu/Colors.h>
#include <SmartString/SmartString.h>
#include <layout/Confirm.h>
#include "View.h"
#include "InputView.h"

class ConfirmView : private View
{
    std::string label;

public:
    ConfirmView(std::istream *const, std::ostream *const, const std::string &);
    void render();
    bool get();
};