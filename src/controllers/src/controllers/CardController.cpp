#include "CardController.h"

CardController::CardController(const GetEnv *const config, std::istream *const input, std::ostream *const output) : Controller(config, input, output)
{
}
void CardController::index(BankAccount *const account)
{
    std::set<std::string>::iterator iter;
    SectionHeaderView header(this->output, "Moje karty");
    MyCardIDsView myCardsView(this->input, this->output, DebitCard::findByAccountID(account->getID()));
    header.render();
    myCardsView.render();
    myCardsView.pressToContinue();
}

void CardController::create(BankAccount *const account)
{
    DebitCard *card;
    char currentEl;
    std::string pinVal;

    NewCardIDView cardID(this->input, this->output);
    SectionHeaderView header(this->output, "Nowa karta");
    PasswordView pin(this->input, this->output, "Wprowadz kod PIN do karty: ");
    header.render();
    pin.render();
    pinVal = pin.get();
    card = DebitCard::make(account->getID(), pinVal);
    cardID.setID(card->store());
    cardID.render();
    cardID.pressToContinue();

    delete card;
}