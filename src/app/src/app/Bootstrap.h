#pragma once

#include <GetEnv/GetEnv.h>

#include <Menu/Colors.h>
#include <Menu/Menu.h>

#include <models/BankAccount.h>

inline void bootstrap(const GetEnv *const config)
{
    // set liblaries global variables 
    colors::useColors = (config->env("USE_COLORS", "true")) == "true";
    menu::useConsoleClear = (config->env("USE_SPACES", "true")) == "true";
    menu::useConsoleHide = (config->env("USE_HIDE", "true")) == "true";
    
    // set models global variables
    BankAccount::filename = config->env("BANK_ACCOUNT_FILENAME", "");
}