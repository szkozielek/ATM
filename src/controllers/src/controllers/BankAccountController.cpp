#include "BankAccountController.h"

BankAccountController::BankAccountController(
    const GetEnv *const config,
    std::istream *const in,
    std::ostream *const out) : Controller(config, in, out) {}

void BankAccountController::create()
{
    BankAccount * newAccount;
    char currentEl;
    std::string pin, cardID;

    menu::clearScreen(*this->output);
    this->output->width(15);
    *this->output << "Wprowadz kod PIN do karty: ";
    menu::hideText(*this->output);
    *this->input >> pin;
    menu::showText(*this->output);
    *this->output << std::endl;
    newAccount = BankAccount::make(pin);
    cardID = newAccount->store();

    *this->output << "Twoj numer karty:\t" << colors::yellow << cardID << colors::white << std::endl;
    this->input->ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    this->input->get();
    this->input->clear();

    delete newAccount;
}

void BankAccountController::getCash()
{
    ATM * atm;
    unsigned int toGet;
    std::map<unsigned int, unsigned int> cashToGive;                                   // temp
    std::map<unsigned int, unsigned int>::iterator cashIter;                           // temp
    std::string selectedOption = "";
    std::map<std::string, std::string> options = {{"1", "50PLN"}, {"2", "100PLN"}, {"3", "150PLN"}, {"4", "200PLN"}, {"5", "300PLN"}, {"6", "400PLN"}, {"7", "500PLN"}, {"8", "Inna kwota"}, {"q", "Powrot"}};
    std::map<std::string, unsigned int> getOptions = {{"1", 50}, {"2", 100}, {"3", 150}, {"4", 200}, {"5", 300}, {"6", 400}, {"7", 500}};
    do
    {
        menu::clearScreen(*this->output);
        *this->output << "Wybierz kwote do wyplaty:" << std::endl;
        if (selectedOption != "" && (options.find(selectedOption) == options.end()))
        {
            layout::show<layout::ValidateError>(this->output, "Wybierz element z listy");
        }
        *this->output << std::endl;
        layout::show<layout::Select>(this->output, options);
        *this->input >> selectedOption;
        selectedOption = smartstring::lower(selectedOption);
        if (selectedOption != "q" && (options.find(selectedOption) != options.end()))
        {
            menu::clearScreen(*this->output);
            if (selectedOption == "8")
            {
                *this->output << colors::white << "Wprowadz kwote: " << colors::yellow;
                *this->input >> toGet;
                *this->output << colors::white;
            }
            else
            {
                *this->output << colors::white << "Wyplacana kwota: " << colors::yellow << options[selectedOption] << colors::white << std::endl;
                toGet = getOptions[selectedOption];
            }

            try
            {
                atm = new ATM(this->config->env("ATM_ID_KEY", "0000"), "PLN");
                cashToGive = changemaking::getCash(atm->getCash(), toGet);
                atm->grabCash(cashToGive);
                atm->update();
                delete atm;
                atm = nullptr;

                *this->output << colors::green;
                menu::line(*this->output, 70);
                *this->output << std::endl << "Odbierz pieniadze z automatu: " << std::endl;
                menu::line(*this->output, 70);
                *this->output << colors::white << std::endl;
                for (cashIter = cashToGive.begin(); cashIter != cashToGive.end(); ++cashIter)
                {
                    *this->output << colors::yellow << std::setw(15) << cashIter->first << "PLN" << colors::white << " => " << colors::green << cashIter->second << std::endl;
                }
                *this->output << colors::green;
                menu::line(*this->output, 70);
                *this->output << std::endl << colors::white;
            }
            catch (except::ImpossibleToChange e)
            {
                if(atm != nullptr){
                    delete atm;
                }
                
                *this->output << colors::red;
                menu::line(*this->output, 70);
                *this->output << std::endl << "Nie mozna wyplacic. Brak dostatecznej liczby banknotow w bankomacie." << std::endl;
                menu::line(*this->output, 70);
                *this->output << std::endl << colors::white << std::endl;
            }
            this->input->ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            this->input->get();
            this->input->clear();
        }
    } while ((options.find(selectedOption) == options.end()));
}

void BankAccountController::insertCash(){
    ATM * atm;
    std::map<unsigned int, unsigned int> cash;
    bool isCurrencyNumber = true, isAmountNumber = true;
    std::string selectedOption = "", currency = "", amount = "";
    unsigned int intCurrency = 0, intAmount = 0;
    size_t divider = 0;

    do{
        menu::clearScreen(*this->output);

        *this->output << colors::red;
        *this->output << std::endl << colors::white << "Aby zakonczyc wplacanie, wprowadz znak \"" << colors::yellow << "q" << colors::white << "\"" << std::endl << colors::red;
        menu::line(*this->output, 42);
        *this->output << std::endl << colors::white;

        if(cash.size() > 0)
        {
            *this->output << std::endl;
            menu::line(*this->output, 42);
            *this->output << std::endl << "Aktualnie wplacono:" << colors::green << std::setw(23) << BankAccountController::sumCash(cash) << colors::white << std::endl;
            menu::line(*this->output, 42);
            *this->output << std::endl;
        }

        if (divider == std::string::npos)
        {
            layout::show<layout::ValidateError>(this->output, "Nieprawidlowy format danych");
        }
        if (!isCurrencyNumber)
        {
            layout::show<layout::ValidateError>(this->output, "Waluta musi byc liczba");
        }
        if (!isAmountNumber)
        {
            layout::show<layout::ValidateError>(this->output, "Ilosc musi byc liczba");
        }

        *this->output << std::endl << "Wprowadz banknoty do wplatomatu (format: " << colors::yellow << "nominal|ilosc" << colors::white << "):" << std::endl << std::endl;
        *this->output << colors::yellow;
        *this->input >> selectedOption;
        *this->output << colors::white;

        isCurrencyNumber = true;
        isAmountNumber = true;
        divider = selectedOption.find('|');
        if(divider != std::string::npos){
            currency = selectedOption.substr(0, divider);
            amount = selectedOption.substr(divider + 1);
            try{
                intCurrency = std::stoul(currency);
                try{
                    intAmount = std::stoul(amount);
                    if(cash.find(intCurrency) == cash.end()){
                        cash.insert(std::pair<unsigned int, unsigned int>(intCurrency, intAmount));
                    }
                    else{
                        cash[intCurrency] = cash[intCurrency] + intAmount;
                    }
                }catch(const std::invalid_argument &e){
                    isAmountNumber = false;
                }
            }catch(const std::invalid_argument &e){
                isCurrencyNumber = false;
            }
        }
        
    }while(selectedOption != "q");

    atm = new ATM(this->config->env("ATM_ID_KEY", "0000"), "PLN");
    atm->insertCash(cash);
    atm->update();
    delete atm;

}


BankAccount * BankAccountController::login(){
    std::string cardID, pin;
    BankAccount * newAccount;

    menu::clearScreen(*this->output);

    this->output->width(15);
    *this->output << "Wprowadz ID karty: " << colors::yellow;
    *this->input >> cardID;
    *this->output << colors::white << std::endl;

    this->output->width(15);
    *this->output << "Wprowadz kod PIN do karty: ";
    menu::hideText(*this->output);
    *this->input >> pin;
    menu::showText(*this->output);

    newAccount = BankAccount::login(cardID, pin);

    return newAccount;
}

unsigned int BankAccountController::sumCash(const std::map<unsigned int, unsigned int> & cash)
{
    std::map<unsigned int, unsigned int>::const_iterator iter;
    unsigned int result = 0;
    for(iter = cash.begin(); iter != cash.end(); iter++){
        result += iter->first * iter->second;
    }
    return result;
}