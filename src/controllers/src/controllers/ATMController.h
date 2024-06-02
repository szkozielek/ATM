#pragma once
#include <iostream>
#include <string>
#include <map>

#include <views/MarkView.h>
#include <views/InputView.h>
#include <views/PasswordView.h>
#include <views/NewCardIDView.h>
#include <views/SelectOptionView.h>
#include <views/CollectMoneyView.h>
#include <views/InsertCashView.h>

#include <GetEnv/GetEnv.h>
#include <ChangeMaking/ChangeMaking.h>
#include <ChangeMaking/ImpossibleToChange.h>

#include <Menu/Menu.h>
#include <SmartString/SmartString.h>

#include <models/BankAccount.h>
#include <models/ATM.h>

#include "Controller.h"
class ATMController : protected Controller
{
    // BankAccount * login();
    unsigned int sumCash(const std::map<unsigned int, unsigned int> &);
public:
    ATMController(const GetEnv * const, std::istream * const, std::ostream * const);
    // void create();
    void index();
    void getCash();
    void insertCash();
};