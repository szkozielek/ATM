#include "BankAccountController.h"

BankAccountController::BankAccountController(std::istream * const in, std::ostream * const out): input(in), output(out){} 

void BankAccountController::create(){
    std::string name, surname;
    unsigned int toGet;
    std::map<unsigned int, unsigned int> cashToGive;
    std::map<unsigned int, unsigned int>::iterator cashIter;

    menu::clearScreen(*this->output);
    // *this->output << "Podaj imie: " << colors::yellow;
    // *this->input >> name;
    // *this->output << colors::white << "Podaj nazwisko: " << colors::yellow;
    // *this->input >> surname;
    // *this->output << colors::white;
    *this->input >> toGet;
    std::map<unsigned int, unsigned int> cash{{20, 1}, {50, 1}, {100, 20}, {200, 10}};
    try{
        cashToGive = changemaking::getCash(cash, toGet);
        for(cashIter = cashToGive.begin(); cashIter != cashToGive.end(); ++cashIter){
            *this->output << colors::yellow << cashIter->first << colors::white << " => " << colors::green << cashIter->second << std::endl;
        }
        *this->output << colors::white;

    }catch(except::ImpossibleToChange e){
        *this->output << colors::red << "Nie udalo sie wyplacic pieniedzy"<< colors::white << std::endl;
    }
    *this->input >> surname;
}