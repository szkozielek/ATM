#pragma once
#include <iostream>
#include <string>
#include <map>
#include <GetEnv/GetEnv.h>
#include <Menu/Colors.h>
#include <Menu/Menu.h>
#include <ChangeMaking/ChangeMaking.h>
#include <ChangeMaking/ImpossibleToChange.h>
#include <SmartString/SmartString.h>
#include "Controller.h"
#include <layout/Select.h>
#include <layout/ValidateError.h>
class BankAccountController : protected Controller{
public:
    BankAccountController(const GetEnv * const, std::istream * const, std::ostream * const);
    void create();
    void getCash();

};