#pragma once
#include <iostream>
#include <string>
#include <set>

#include <GetEnv/GetEnv.h>
#include <Menu/Menu.h>

#include <models/BankAccount.h>
#include <models/DebitCard.h>

#include <views/PasswordView.h>
#include <views/NewCardIDView.h>
#include <views/SectionHeaderView.h>
#include <views/MyCardIDsView.h>

#include "Controller.h"

class CardController : Controller
{
public:
    CardController(const GetEnv *const, std::istream *const, std::ostream *const);
    void index(BankAccount *const);
    void create(BankAccount *const);
};