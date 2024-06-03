#include "CardController.h"

CardController::CardController(const GetEnv *const config, std::istream *const input, std::ostream *const output) : Controller(config, input, output)
{
}

void CardController::create(BankAccount *const account)
{
    DebitCard *card;
    char currentEl;
    PasswordView pin(this->input, this->output, "Wprowadz kod PIN do karty: ");
    NewCardIDView cardID(this->input, this->output);
    menu::clearScreen(*this->output);
    pin.render();
    card = DebitCard::make(account->getID(), pin.get());
    cardID.setID(card->store());
    cardID.render();
    cardID.pressToContinue();

    delete card;
}