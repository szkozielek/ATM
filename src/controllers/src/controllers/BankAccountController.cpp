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

    delete newAccount;
}

void BankAccountController::getCash()
{
    unsigned int toGet;
    std::map<unsigned int, unsigned int> cash{{20, 1}, {50, 1}, {100, 20}, {200, 10}}; // temp
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
                cashToGive = changemaking::getCash(cash, toGet);
                *this->output << colors::green << "Odbierz pieniadze z automatu: " << colors::white << std::endl;
                for (cashIter = cashToGive.begin(); cashIter != cashToGive.end(); ++cashIter)
                {
                    this->output->width(15);
                    *this->output << colors::yellow << cashIter->first << "PLN" << colors::white << " => " << colors::green << cashIter->second << std::endl;
                }
                *this->output << colors::white;
            }
            catch (except::ImpossibleToChange e)
            {
                *this->output << colors::red << "Nie mozna wyplacic. Brak dostatecznej liczby banknotow w bankomacie." << colors::white << std::endl;
            }
            this->input->ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            this->input->get();
        }
    } while ((options.find(selectedOption) == options.end()));
}

void BankAccountController::login(){
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
    

}