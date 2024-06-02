#pragma once
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <FileManager/FileReader.h>
#include <FileManager/FileWriter.h>

class BankAccountBallance
{
    std::string currency;
    unsigned long long accountID;
    std::string getFilePath();
    void store(unsigned int, char);
public:
    static std::string filedir;
    BankAccountBallance(unsigned long long, const std::string &);
    unsigned long long get();
    void withdraw(unsigned int);
    void deposit(unsigned int);
};