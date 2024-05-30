#pragma once
#include <iostream>
#include <string>
#include <set>
#include <Menu/Menu.h>
#include <layout/Select.h>
#include <layout/ValidateError.h>
#include "View.h"

class SelectOptionView : private View
{
    std::string label;
    std::set<std::string> errors;
    std::map<std::string, std::string> options;
    
    inline void clearErrors(){ this->errors.clear(); }
    void standardValidation(const std::string &);
public:
    SelectOptionView(std::istream *const, std::ostream *const, const std::string &, const std::map<std::string, std::string> &);
    inline void addError(const std::string & error){ this->errors.insert(error); }
    void render();
    std::string select();
};