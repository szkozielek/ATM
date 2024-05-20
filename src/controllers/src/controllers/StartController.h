#pragma once
#include <iostream>
#include <string>
#include <set>

#include <GetEnv/GetEnv.h>
#include <SmartString/SmartString.h>

#include <layout/Cover.h>
#include <layout/ValidateError.h>
#include <layout/Select.h>
#include "Controller.h"
#include "BankAccountController.h"

class StartController : protected Controller{
public:
    StartController(const GetEnv * const, std::istream * const, std::ostream * const);
    void cover();
    void index();
};