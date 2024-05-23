#pragma once
#include <iostream>
#include <string>
#include <map>
#include <iomanip>

#include <GetEnv/GetEnv.h>
#include <ChangeMaking/ChangeMaking.h>
#include <ChangeMaking/ImpossibleToChange.h>

#include <Menu/Colors.h>
#include <Menu/Menu.h>
#include <SmartString/SmartString.h>

#include <layout/Select.h>
#include <layout/ValidateError.h>
#include <layout/Password.h>

#include <models/BankAccount.h>

#include "Controller.h"
class BankAccountController : protected Controller{
    BankAccount * login();
    unsigned int sumCash(const std::map<unsigned int, unsigned int> &);
public:
    BankAccountController(const GetEnv * const, std::istream * const, std::ostream * const);
    void create();
    void getCash();
    void insertCash();
    

};