#pragma once
#include <iostream>
#include <string>
#include <map>

#include <FileManager/FileNotFound.h>
#include <GetEnv/GetEnv.h>
#include <Menu/Menu.h>

#include <models/BankAccount.h>
#include <models/BankAccountBallance.h>

#include <views/SelectOptionView.h>
#include <views/InputView.h>
#include <views/PasswordView.h>
#include <views/ConfirmView.h>
#include <views/ErrorView.h>
#include <views/MarkView.h>
#include <views/SectionHeaderView.h>
#include <views/BallanceView.h>

#include <services/CurrencyService.h>

#include <exceptions/BadCredentials.h>
#include <exceptions/LoginInUse.h>

#include "Controller.h"
#include "CardController.h"

class BankAccountController : Controller
{
    BankAccount *account;
    void login();
    void logout();

public:
    BankAccountController(const GetEnv *const, std::istream *const, std::ostream *const);
    void index();
    void create();
    void show();
    ~BankAccountController();
};