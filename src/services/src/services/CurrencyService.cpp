#include "CurrencyService.h"

std::map<std::string, std::string> CurrencyService::getOptions(std::string currencies)
{
    size_t pos;
    unsigned int iter = 0;
    std::map<std::string, std::string> options;
    // currencies = this->config->env("CURRENCIES", "");
    while( (pos = currencies.find(";")) != std::string::npos )
    {

        options.insert(std::make_pair<std::string, std::string>(std::to_string(++iter), currencies.substr(0, pos)));
        currencies.erase(0, pos + 1);
    }
    if(currencies.size() > 0){
        options.insert(std::make_pair<std::string, std::string>(std::to_string(++iter), currencies.substr(0)));
    }
    return options;
}

    // options.insert(std::make_pair<std::string, std::string>("q", "Powrot"));

    // SelectOptionView select(this->input, this->output, "Wybierz walute:",  options);
    // select.render();
    // return select.select();