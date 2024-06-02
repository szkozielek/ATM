#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include <FileManager/FileReader.h>
#include <FileManager/FileWriter.h>
#include <Hash/Hash.h>


class DebitCard
{
    static std::string getFilePath();

    std::string pin, cardID;
    unsigned long long accountID;

    void generateCardID();

    DebitCard(unsigned long long, const std::string &);
    
public:
    static std::string filename;
    static std::string filedir;
    static DebitCard * make(unsigned long long, const std::string &);
    std::string store();
};


// #pragma once
// #include <iostream>
// #include <string>
// #include <exception>
// #include <stdexcept>
// #include <algorithm>
// #include <FileManager/FileReader.h>
// #include <FileManager/FileWriter.h>
// #include <Hash/Hash.h>

// class BankAccount{

//     static std::string getFilePath();
//     static bool checkIfValid(const std::string &, const std::string &);
    
//     std::string pin, cardID;

//     void generateCardID();

//     BankAccount(const std::string &);
//     BankAccount(const std::string &, const std::string &);

// public:
//     static std::string filename;
//     static std::string filedir;
//     static BankAccount * make(const std::string &);
//     static BankAccount * login(const std::string &, const std::string &);
//     std::string store();

// };