#include "BankAccountController.h"

BankAccountController::BankAccountController(const GetEnv * const config, std::istream * const input, std::ostream * const output) : Controller(config, input, output), account(nullptr)
{

}

void BankAccountController::index()
{
    std::string selectedOption = "";
    CardController * cardCtrl;
    SelectOptionView select(this->input, this->output, "Zarzadzanie kontem. Wybierz opcje:", {
        {"1", "Sprawdz saldo"}, 
        {"2", "Zamow karte"}, 
        {"q", "Wyloguj"}
    });
    this->login();
    if(this->account == nullptr){
        return;
    }
    do
    {
        select.render();
        selectedOption = smartstring::lower(select.select());
        if (selectedOption == "1")
        {
            this->show();
        }
        else if (selectedOption == "2")
        {
            cardCtrl = new CardController(this->config, this->input, this->output);
            cardCtrl->create(this->account);
            delete cardCtrl;
        }
    } while (selectedOption != "q");
    this->logout();
}

void BankAccountController::create()
{
    bool done = false;
    std::string login, password;
    BankAccount * account;
    InputView<std::string> loginInput(this->input, this->output, "Wprowadz login: ");
    PasswordView passwordInput(this->input, this->output, "Wprowadz haslo: ");
    ConfirmView tryAgain(this->input, this->output, "Czy chcesz sprobowac jeszcze raz?");
    do{
        menu::clearScreen(*this->output);
        loginInput.render();
        login = loginInput.get();
        passwordInput.render();
        password = passwordInput.get();
        try {
            account = BankAccount::make(login, password);
            account->store();
            delete account;
            done = true;
        } catch(const std::exception & e)
        {
            ErrorView error(this->output, "Podany login jest juz zajety.");
            error.render();
            tryAgain.render();
            done = !tryAgain.get();
        }
    } while(!done);
}

void BankAccountController::show()
{
    
}

void BankAccountController::login()
{
    bool done = false;
    std::string login, password;
    InputView<std::string> loginInput(this->input, this->output, "Wprowadz login: ");
    PasswordView passwordInput(this->input, this->output, "Wprowadz haslo: ");
    ConfirmView tryAgain(this->input, this->output, "Czy chcesz sprobowac jeszcze raz?");
    do{
        menu::clearScreen(*this->output);
        loginInput.render();
        login = loginInput.get();
        passwordInput.render();
        password = passwordInput.get();
        try {
            this->account = BankAccount::login(login, password);
            done = true;
        } catch(const std::exception & e)
        {
            ErrorView error(this->output, "Podane dane sa nieprawidlowe.");
            error.render();
            tryAgain.render();
            done = !tryAgain.get();
        }
    } while(!done);
}

void BankAccountController::logout()
{
    if(this->account != nullptr){
        delete this->account;
        this->account = nullptr;
    }
}

BankAccountController::~BankAccountController(){
    this->logout();
}