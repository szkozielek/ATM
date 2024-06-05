#pragma once
#include <string>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <FileManager/FileReader.h>
#include <FileManager/FileWriter.h>
#include <Hash/Hash.h>
#include <exceptions/BadCredentials.h>
#include <exceptions/LoginInUse.h>

class BankAccount
{
private:
    unsigned long long _id;
    std::string _login, _password;

private:
    static std::string getFilePath();
    static bool checkIfExist(const std::string &);
    static unsigned long long findID(const std::string &, const std::string &);

    BankAccount(const std::string &, const std::string &);
    BankAccount(unsigned long long, const std::string &, const std::string &);
    void generateID();

public:
    static std::string filename;
    static std::string filedir;

public:
    static BankAccount *make(const std::string &, const std::string &);
    static BankAccount *login(const std::string &, const std::string &);
    unsigned long long store();
    unsigned long long getID() const;
    std::string getLogin() const;
};