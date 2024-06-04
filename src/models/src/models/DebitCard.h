#pragma once
#include <iostream>
#include <string>
#include <set>
#include <exception>
#include <stdexcept>

#include <FileManager/FileReader.h>
#include <FileManager/FileWriter.h>
#include <Hash/Hash.h>

class DebitCard
{
    static std::string getFilePath();
    static unsigned long long findID(const std::string &, const std::string &);

    std::string pin, cardID;
    unsigned long long accountID;

    void generateCardID();

    DebitCard(unsigned long long, const std::string &);
    DebitCard(const std::string &, const std::string &);

public:
    static std::string filename;
    static std::string filedir;
    static DebitCard *make(unsigned long long, const std::string &);
    static DebitCard *login(const std::string &, const std::string &);
    static std::set<std::string> findByAccountID(unsigned long long);
    std::string store();
    unsigned long long getAccountID();
};