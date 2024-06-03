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
#include <views/ConfirmView.h>

#include <GetEnv/GetEnv.h>
#include <ChangeMaking/ChangeMaking.h>
#include <ChangeMaking/ImpossibleToChange.h>

#include <Menu/Menu.h>
#include <SmartString/SmartString.h>

#include <models/DebitCard.h>
#include <models/BankAccountBallance.h>
#include <models/ATM.h>

#include <services/CurrencyService.h>

#include "Controller.h"
class ATMController : protected Controller
{
    DebitCard * card;
    void insertCard();
    void drawCard();
    unsigned int sumCash(const std::map<unsigned int, unsigned int> &);
    std::string selectCurrency();

public:
    ATMController(const GetEnv * const, std::istream * const, std::ostream * const);
    void index();
    void getCash();
    void insertCash();
};