#pragma once
#include <string>
#include <map>

class CurrencyService
{
public:
    std::map<std::string, std::string> getOptions(std::string);
};