#pragma once

#include <map>
#include <string>
#include <iomanip>
#include <Menu/Colors.h>
#include <Menu/Menu.h>
#include "View.h"

class BallanceView : public View
{
    std::map<std::string, unsigned long long> ballance;

public:
    BallanceView(std::istream *const, std::ostream *const);
    void setBallance(const std::map<std::string, unsigned long long> &);
    void render();
};