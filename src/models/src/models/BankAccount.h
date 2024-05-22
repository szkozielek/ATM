#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <FileManager/FileReader.h>
#include <FileManager/FileWriter.h>

class BankAccount{
    
    std::string pin, cardID;
    unsigned int amount;
    void generateCardID();
public:
    static std::string filename;
    BankAccount(const std::string &);
    std::string getCardID();
    void store();
};