#include "ATMController.h"

ATMController::ATMController(
    const GetEnv * const config,
    std::istream * const in,
    std::ostream * const out
) : Controller(config, in, out) 
{

}

// void BankAccountController::create()
// {
//     BankAccount * newAccount;
//     char currentEl;
//     PasswordView pin(this->input, this->output, "Wprowadz kod PIN do karty: ");
//     NewCardIDView cardID(this->input, this->output);

//     pin.render();
//     newAccount = BankAccount::make(pin.get());
//     cardID.setID(newAccount->store());
//     cardID.render();
//     cardID.pressToContinue();

//     delete newAccount;
// }

void ATMController::index()
{
    std::string selectedOption = "";
    SelectOptionView select(this->input, this->output, "Bankomat. Wybierz opcje:", {
        {"1", "Wyplac pieniadze"}, 
        {"2", "Wplac pieniadze"}, 
        {"q", "Powrot"}
    });
    do
    {
        select.render();
        selectedOption = smartstring::lower(select.select());
        if (selectedOption == "1")
        {
            this->getCash();
        }
        else if (selectedOption == "2")
        {
            this->insertCash();
        }
    } while (selectedOption != "q");
}

void ATMController::getCash()
{
    ATM * atm;
    unsigned int toGet;
    std::map<unsigned int, unsigned int> cashToGive;                                   // temp
    std::map<unsigned int, unsigned int>::iterator cashIter;                           // temp
    std::string selectedOption, selectedCurrency = "PLN";
    InputView<unsigned int> amountInput(this->input, this->output, "Wprowadz kwote: ");
    MarkView<std::string> amountMark(this->output, "Wyplacana kwota: ");
    CollectMoneyView collectMoney(this->input, this->output, "Odbierz pieniadze z automatu: ");
    SelectOptionView select(this->input, this->output, "Wybierz kwote do wyplaty:",  {
        {"1", "50" + selectedCurrency}, {"2", "100" + selectedCurrency}, {"3", "150" + selectedCurrency}, 
        {"4", "200" + selectedCurrency}, {"5", "300" + selectedCurrency}, {"6", "400" + selectedCurrency}, 
        {"7", "500" + selectedCurrency}, {"8", "Inna kwota"}, {"q", "Powrot"}
    });
    std::map<std::string, unsigned int> getOptions = {
        {"1", 50}, {"2", 100}, {"3", 150}, 
        {"4", 200}, {"5", 300}, {"6", 400}, 
        {"7", 500}, {"8", 0}, {"q", 0}
    };
    collectMoney.setCurrency(selectedCurrency);
    do
    {
        select.render();
        selectedOption = smartstring::lower(select.select());
        if (selectedOption != "q"  && (getOptions.find(selectedOption) != getOptions.end()))
        {
            menu::clearScreen(*this->output);
            if (selectedOption == "8")
            {
                amountInput.render();
                toGet = amountInput.get();
            }
            else
            {
                amountMark.render(std::to_string(getOptions[selectedOption]) + selectedCurrency);
                toGet = getOptions[selectedOption];
            }

            try
            {
                atm = new ATM(this->config->env("ATM_ID_KEY", "0000"), selectedCurrency);
                cashToGive = changemaking::getCash(atm->getCash(), toGet);
                atm->grabCash(cashToGive);
                atm->update();
                delete atm;
                atm = nullptr;
                collectMoney.setCash(cashToGive);
                collectMoney.render();
            }
            catch (except::ImpossibleToChange e)
            {
                if(atm != nullptr){
                    delete atm;
                }
                collectMoney.render("Nie mozna wyplacic. Brak dostatecznej liczby banknotow w bankomacie.");
            }
            collectMoney.pressToContinue();
        }
    } while (getOptions.find(selectedOption) == getOptions.end());
}

void ATMController::insertCash(){
    ATM * atm;
    std::map<unsigned int, unsigned int> cash;
    bool isCurrencyNumber = true, isAmountNumber = true;
    std::string selectedOption = "", currency = "", amount = "", selectedCurrency = "PLN";
    unsigned int intCurrency = 0, intAmount = 0;
    size_t divider = 0;
    InsertCashView insertCash(this->input, this->output, selectedCurrency);

    do{
        insertCash.setCash(ATMController::sumCash(cash));
        if (divider == std::string::npos)
        {
            insertCash.addError("Nieprawidlowy format danych");
        }
        if (!isCurrencyNumber)
        {
            insertCash.addError("Waluta musi byc liczba");
        }
        if (!isAmountNumber)
        {
            insertCash.addError("Ilosc musi byc liczba");
        }
        insertCash.render();
        selectedOption = insertCash.insert();

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

    atm = new ATM(this->config->env("ATM_ID_KEY", "0000"), selectedCurrency);
    atm->insertCash(cash);
    atm->update();
    delete atm;

}


// BankAccount * BankAccountController::login(){
//     std::string cardID, pin;
//     BankAccount * newAccount;

//     menu::clearScreen(*this->output);

//     this->output->width(15);
//     *this->output << "Wprowadz ID karty: " << colors::yellow;
//     *this->input >> cardID;
//     *this->output << colors::white << std::endl;

//     this->output->width(15);
//     *this->output << "Wprowadz kod PIN do karty: ";
//     menu::hideText(*this->output);
//     *this->input >> pin;
//     menu::showText(*this->output);

//     newAccount = BankAccount::login(cardID, pin);

//     return newAccount;
// }

unsigned int ATMController::sumCash(const std::map<unsigned int, unsigned int> & cash)
{
    std::map<unsigned int, unsigned int>::const_iterator iter;
    unsigned int result = 0;
    for(iter = cash.begin(); iter != cash.end(); iter++){
        result += iter->first * iter->second;
    }
    return result;
}