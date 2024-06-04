#pragma once
#include <set>
#include <Menu/Menu.h>
#include <Menu/Colors.h>
#include "View.h"
#include "ErrorView.h"
class MyCardIDsView : public View
{
    std::set<std::string> cardIDs;

public:
    MyCardIDsView(std::istream *const, std::ostream *const, const std::set<std::string> &);
    void render();
};