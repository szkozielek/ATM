#pragma once
#include <iostream>
#include <set>
#include <string>
#include <iomanip>
#include <Menu/Colors.h>
#include <Menu/Menu.h>
#include <layout/ValidateError.h>
#include "View.h"

class InsertCashView : private View
{
    unsigned int cash;
    std::string currency;
    std::set<std::string> errors;
    inline void clearErrors(){ this->errors.clear(); }
public:
    InsertCashView(std::istream * const, std::ostream * const, const std::string &);
    void render();
    std::string insert();
    inline void addError(const std::string & error){ this->errors.insert(error); }
    inline void setCash(const unsigned int & cash) { this->cash = cash; }
};