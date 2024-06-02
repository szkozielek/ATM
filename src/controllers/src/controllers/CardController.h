#pragma once
#include <iostream>
#include <string>

#include <GetEnv/GetEnv.h>
#include <Menu/Menu.h>

#include <models/BankAccount.h>
#include <models/DebitCard.h>

#include <views/PasswordView.h>
#include <views/NewCardIDView.h>

#include "Controller.h"

class CardController : Controller
{
public:
    CardController(const GetEnv * const, std::istream * const, std::ostream * const);
    void create(BankAccount * const);
};