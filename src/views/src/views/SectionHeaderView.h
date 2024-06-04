#pragma once
#include <Menu/Menu.h>
#include <layout/Header.h>
#include "View.h"

class SectionHeaderView : View
{
    std::string label;

public:
    SectionHeaderView(std::ostream *const, const std::string &);
    void render();
};