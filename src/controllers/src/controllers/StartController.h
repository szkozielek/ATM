#pragma once
#include <iostream>
#include <string>
#include <set>

#include <GetEnv/GetEnv.h>
#include <SmartString/SmartString.h>

#include <views/SelectOptionView.h>
#include <views/CoverView.h>
#include <views/SectionHeaderView.h>

#include "Controller.h"
#include "ATMController.h"
#include "BankController.h"

class StartController : protected Controller
{
public:
    StartController(const GetEnv *const, std::istream *const, std::ostream *const);
    void index();
};