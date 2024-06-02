#pragma once
#include <iostream>
#include <string>
#include <set>

#include <GetEnv/GetEnv.h>
#include <SmartString/SmartString.h>

#include <layout/Cover.h>

#include <views/SelectOptionView.h>

#include "Controller.h"
#include "ATMController.h"
#include "BankController.h"

class StartController : protected Controller
{
public:
    StartController(const GetEnv *const, std::istream *const, std::ostream *const);
    void index();
};