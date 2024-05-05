#pragma once
#include <iostream>
#include <string>
#include <Menu/Colors.h>
#include <Menu/Menu.h>
class BankAccountController{
    std::istream * const input;
    std::ostream * const output;
public:
    BankAccountController(std::istream * const, std::ostream * const);
    void create();

};