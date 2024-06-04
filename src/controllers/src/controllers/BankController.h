#pragma once
#include <SmartString/SmartString.h>
#include <Menu/Menu.h>
#include <GetEnv/GetEnv.h>

#include <views/SelectOptionView.h>
#include <views/InputView.h>
#include <views/PasswordView.h>
#include <views/ConfirmView.h>
#include <views/ErrorView.h>
#include <views/SectionHeaderView.h>

#include "Controller.h"
#include "BankAccountController.h"

class BankController : Controller
{
public:
    BankController(const GetEnv *const, std::istream *const, std::ostream *const);
    void index();
};