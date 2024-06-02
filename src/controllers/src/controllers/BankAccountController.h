#pragma once
#include <iostream>
#include <string>

#include <GetEnv/GetEnv.h>

#include <models/BankAccount.h>
#include <views/SelectOptionView.h>
#include <views/InputView.h>
#include <views/PasswordView.h>
#include <views/ConfirmView.h>
#include <views/ErrorView.h>

#include "Controller.h"
#include "CardController.h"

class BankAccountController : Controller 
{
    BankAccount * account;
    void login();
    void logout();
public:
    BankAccountController(const GetEnv * const, std::istream * const, std::ostream * const);
    void index();
    void create();
    void show();
    ~BankAccountController();
};