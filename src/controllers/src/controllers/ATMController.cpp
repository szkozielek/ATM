#include "ATMController.h"

ATMController::ATMController(
    const GetEnv *const config,
    std::istream *const in,
    std::ostream *const out) : Controller(config, in, out), card(nullptr)
{
}

void ATMController::insertCard()
{
    bool done = false;
    std::string cardID, pin;
    SectionHeaderView header(this->output, "Bankomat - logowanie");
    InputView<std::string> loginInput(this->input, this->output, "Wprowadz karte: ");
    PasswordView passwordInput(this->input, this->output, "Wprowadz pin: ");
    ConfirmView tryAgain(this->input, this->output, "Czy chcesz sprobowac jeszcze raz?");
    do
    {
        header.render();
        loginInput.render();
        cardID = loginInput.get();
        passwordInput.render();
        pin = passwordInput.get();
        try
        {
            this->card = DebitCard::login(cardID, pin);
            done = true;
        }
        catch (const std::exception &e)
        {
            ErrorView error(this->output, "Podane dane sa nieprawidlowe.");
            error.render();
            tryAgain.render();
            done = !tryAgain.get();
        }
    } while (!done);
}

void ATMController::drawCard()
{
    if (this->card != nullptr)
    {
        delete this->card;
        this->card = nullptr;
    }
}

void ATMController::index()
{
    std::string selectedOption = "";
    SectionHeaderView header(this->output, "Bankomat");
    SelectOptionView select(this->input, this->output, "Wybierz opcje:", {{"1", "Wyplac pieniadze"}, {"2", "Wplac pieniadze"}, {"q", "Powrot"}});
    this->insertCard();
    if (this->card == nullptr)
    {
        return;
    }
    do
    {
        header.render();
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
    this->drawCard();
}

void ATMController::getCash()
{
    ATM *atm = nullptr;
    BankAccountBallance *ballance = nullptr;
    unsigned long long toGet;
    std::map<unsigned int, unsigned int> cashToGive;
    std::map<unsigned int, unsigned int>::iterator cashIter;
    std::string selectedOption, header = "Bankomat - wyplata", selectedCurrency = this->selectCurrency(header);
    InputView<unsigned int> amountInput(this->input, this->output, "Wprowadz kwote: ");
    MarkView<std::string> amountMark(this->output, "Wyplacana kwota: ");
    CollectMoneyView collectMoney(this->input, this->output, "Odbierz pieniadze z automatu: ");
    SelectOptionView select(this->input, this->output, "Wybierz kwote do wyplaty:", {{"1", "50" + selectedCurrency}, {"2", "100" + selectedCurrency}, {"3", "150" + selectedCurrency}, {"4", "200" + selectedCurrency}, {"5", "300" + selectedCurrency}, {"6", "400" + selectedCurrency}, {"7", "500" + selectedCurrency}, {"8", "Inna kwota"}, {"q", "Powrot"}});
    SectionHeaderView headerView(this->output, header + " " + selectedCurrency);
    std::map<std::string, unsigned int> getOptions = {
        {"1", 50}, {"2", 100}, {"3", 150}, {"4", 200}, {"5", 300}, {"6", 400}, {"7", 500}, {"8", 0}, {"q", 0}};
    if (selectedCurrency == "q")
    {
        return;
    }
    collectMoney.setCurrency(selectedCurrency);
    do
    {
        headerView.render();
        select.render();
        selectedOption = smartstring::lower(select.select());
        if (selectedOption != "q" && (getOptions.find(selectedOption) != getOptions.end()))
        {
            headerView.render();
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
                ballance = new BankAccountBallance(this->card->getAccountID(), selectedCurrency);
                if (ballance->get() < toGet)
                {
                    throw std::exception();
                }
                atm = new ATM(this->config->env("ATM_ID_KEY", "0000"), selectedCurrency);
                cashToGive = changemaking::getCash(atm->getCash(), toGet);
                atm->grabCash(cashToGive);
                atm->update();
                ballance->withdraw(toGet);
                delete ballance;
                ballance = nullptr;
                delete atm;
                atm = nullptr;
                collectMoney.setCash(cashToGive);
                collectMoney.render();
            }
            catch (except::ImpossibleToChange e)
            {
                if (atm != nullptr)
                {
                    delete atm;
                }
                if (ballance != nullptr)
                {
                    delete ballance;
                }
                collectMoney.render("Nie mozna wyplacic. Brak dostatecznej liczby banknotow w bankomacie.");
            }
            catch (std::exception e)
            {
                if (atm != nullptr)
                {
                    delete atm;
                }
                if (ballance != nullptr)
                {
                    delete ballance;
                }
                collectMoney.render("Nie mozna wyplacic. Brak wystarczajacych srodkow na koncie.");
            }
            collectMoney.pressToContinue();
        }
    } while (getOptions.find(selectedOption) == getOptions.end());
}

void ATMController::insertCash()
{
    ATM *atm;
    BankAccountBallance *ballance;
    std::map<unsigned int, unsigned int> cash;
    bool isCurrencyNumber = true, isAmountNumber = true;
    std::string selectedOption = "", currency = "", amount = "", header = "Bankomat - Wplacanie", selectedCurrency = this->selectCurrency(header);
    unsigned int intCurrency = 0, intAmount = 0;
    size_t divider = 0;
    InsertCashView insertCash(this->input, this->output, selectedCurrency);
    SectionHeaderView headerView(this->output, header + " " + selectedCurrency);

    do
    {
        headerView.render();
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
        if (divider != std::string::npos)
        {
            currency = selectedOption.substr(0, divider);
            amount = selectedOption.substr(divider + 1);
            try
            {
                intCurrency = std::stoul(currency);
                try
                {
                    intAmount = std::stoul(amount);
                    if (cash.find(intCurrency) == cash.end())
                    {
                        cash.insert(std::pair<unsigned int, unsigned int>(intCurrency, intAmount));
                    }
                    else
                    {
                        cash[intCurrency] = cash[intCurrency] + intAmount;
                    }
                }
                catch (const std::invalid_argument &e)
                {
                    isAmountNumber = false;
                }
            }
            catch (const std::invalid_argument &e)
            {
                isCurrencyNumber = false;
            }
        }

    } while (selectedOption != "q");
    ballance = new BankAccountBallance(this->card->getAccountID(), selectedCurrency);
    atm = new ATM(this->config->env("ATM_ID_KEY", "0000"), selectedCurrency);
    atm->insertCash(cash);

    atm->update();
    ballance->deposit(ATMController::sumCash(cash));
    delete atm;
    delete ballance;
}

unsigned int ATMController::sumCash(const std::map<unsigned int, unsigned int> &cash)
{
    std::map<unsigned int, unsigned int>::const_iterator iter;
    unsigned int result = 0;
    for (iter = cash.begin(); iter != cash.end(); iter++)
    {
        result += iter->first * iter->second;
    }
    return result;
}

std::string ATMController::selectCurrency(const std::string &headerLabel)
{
    size_t pos;
    unsigned int iter = 0;
    std::string selectedVal;
    CurrencyService service;
    SectionHeaderView header(this->output, headerLabel);
    std::map<std::string, std::string> options(service.getOptions(this->config->env("CURRENCIES", "PLN")));
    options.insert(std::make_pair<std::string, std::string>("q", "Powrot"));

    SelectOptionView select(this->input, this->output, "Wybierz walute:", options);
    header.render();
    select.render();
    selectedVal = select.select();
    if (selectedVal == "q")
    {
        return selectedVal;
    }
    return options[selectedVal];
}