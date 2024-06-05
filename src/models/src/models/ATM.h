#pragma once
#include <map>
#include <string>
#include <iterator>

#include <FileManager/FileReader.h>
#include <FileManager/FileWriter.h>
#include <exceptions/LackOfAccountFunds.h>

class ATM
{
    std::string UUID, currency;
    std::map<unsigned int, unsigned int> *cash;

    void loadCash();
    std::string getFilePath();

public:
    static std::string filedir;

    ATM(const std::string &, const std::string &);
    std::map<unsigned int, unsigned int> getCash();
    void insertCash(const std::map<unsigned int, unsigned int> &);
    void grabCash(const std::map<unsigned int, unsigned int> &);
    void update();
    ~ATM();
};