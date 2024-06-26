#pragma once

#include <GetEnv/GetEnv.h>

#include <Menu/Colors.h>
#include <Menu/Menu.h>

#include <models/BankAccount.h>
#include <models/BankAccountBallance.h>
#include <models/DebitCard.h>
#include <models/ATM.h>

inline void init(const GetEnv *const config)
{
    // set liblaries global variables
    colors::useColors = (config->env("USE_COLORS", "true")) == "true";
    menu::useConsoleClear = (config->env("USE_SPACES", "true")) == "true";
    menu::useConsoleHide = (config->env("USE_HIDE", "true")) == "true";

    // set models global variables
    BankAccount::filedir = config->env("BANK_ACCOUNT_DIR", "");
    BankAccount::filename = config->env("BANK_ACCOUNT_FILENAME", "");

    DebitCard::filedir = config->env("DEBIT_CARD_DIR", "");
    DebitCard::filename = config->env("DEBIT_CARD_FILENAME", "");

    ATM::filedir = config->env("ATM_CASHBOX_DIR", "");
    BankAccountBallance::filedir = config->env("ACCOUNT_BALANCE_DIR", "");
}