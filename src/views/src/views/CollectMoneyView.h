#pragma once

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <Menu/Menu.h>
#include <Menu/Colors.h>
#include "View.h"
#include "ErrorView.h"

class CollectMoneyView : public View
{
    std::map<unsigned int, unsigned int> cash;
    std::string currency, label;
public:
    CollectMoneyView(std::istream * const, std::ostream * const, const std::string &);
    inline void setCurrency(const std::string & currency) { this->currency = currency; }
    inline void setCash(const std::map<unsigned int, unsigned int> & cash) { this->cash = cash; }
    void render();
    void render(const std::string &);
};