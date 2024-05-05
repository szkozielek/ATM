#include "BankAccountController.h"

BankAccountController::BankAccountController(std::istream * const in, std::ostream * const out): input(in), output(out){} 

void BankAccountController::create(){
    std::string name, surname;
    menu::clearScreen(*this->output);
    *this->output << "Podaj imie: " << colors::yellow;
    *this->input >> name;
    *this->output << colors::white << "Podaj nazwisko: " << colors::yellow;
    *this->input >> surname;
    *this->output << colors::white;
}