#include "BankAccountController.h"

BankAccountController::BankAccountController(const GetEnv *const config, std::istream *const input, std::ostream *const output) : Controller(config, input, output), account(nullptr)
{
}

void BankAccountController::index()
{
    std::string selectedOption = "";
    CardController *cardCtrl;
    SelectOptionView select(this->input, this->output, "Wybierz opcje:", {{"1", "Sprawdz saldo"}, {"2", "Zamow karte"}, {"3", "Moje karty"}, {"q", "Wyloguj"}});
    this->login();
    if (this->account == nullptr)
    {
        return;
    }
    SectionHeaderView header(this->output, "Konto - \"" + this->account->getLogin() + "\"");
    do
    {
        header.render();
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
        else if (selectedOption == "3")
        {
            cardCtrl = new CardController(this->config, this->input, this->output);
            cardCtrl->index(this->account);
            delete cardCtrl;
        }
    } while (selectedOption != "q");
    this->logout();
}

void BankAccountController::create()
{
    bool done = false;
    std::string login, password;
    BankAccount *account;
    InputView<std::string> loginInput(this->input, this->output, "Wprowadz login: ");
    PasswordView passwordInput(this->input, this->output, "Wprowadz haslo: ");
    SectionHeaderView header(this->output, "Dodawanie konta");
    ConfirmView tryAgain(this->input, this->output, "Czy chcesz sprobowac jeszcze raz?");
    do
    {
        header.render();
        loginInput.render();
        login = loginInput.get();
        passwordInput.render();
        password = passwordInput.get();
        try
        {
            account = BankAccount::make(login, password);
            account->store();
            delete account;
            done = true;
        }
        catch (const except::FileNotFound &e)
        {
            ErrorView error(this->output, "Nie znaleziono pliku z kontami bankowymi.");
            error.render();
            throw e;
        }
        catch (const except::LoginInUse &e)
        {
            ErrorView error(this->output, "Podany login jest juz zajety.");
            error.render();
            tryAgain.render();
            done = !tryAgain.get();
        }
    } while (!done);
}

void BankAccountController::show()
{
    std::map<std::string, std::string> currencies;
    std::map<std::string, unsigned long long> ballanceMap;
    std::map<std::string, std::string>::iterator iter;
    SectionHeaderView header(this->output, "Saldo konta");
    BallanceView ballanceView(this->input, this->output);
    CurrencyService service;
    BankAccountBallance *ballance = nullptr;

    currencies = service.getOptions(this->config->env("CURRENCIES", "PLN"));
    header.render();
    for (iter = currencies.begin(); iter != currencies.end(); ++iter)
    {
        try
        {
            ballance = new BankAccountBallance(this->account->getID(), iter->second);
            ballanceMap.insert(std::pair<std::string, unsigned long long>(iter->second, ballance->get()));
            delete ballance;
            ballance = nullptr;
        }
        catch (const except::FileNotFound &e)
        {
            ballanceMap.insert(std::pair<std::string, unsigned long long>(iter->second, 0));
            if (ballance != nullptr)
            {
                delete ballance;
                ballance = nullptr;
            }
        }
    }
    ballanceView.setBallance(ballanceMap);
    ballanceView.render();
    ballanceView.pressToContinue();
}

void BankAccountController::login()
{
    bool done = false;
    std::string login, password;
    InputView<std::string> loginInput(this->input, this->output, "Wprowadz login: ");
    PasswordView passwordInput(this->input, this->output, "Wprowadz haslo: ");
    ConfirmView tryAgain(this->input, this->output, "Czy chcesz sprobowac jeszcze raz?");
    SectionHeaderView header(this->output, "Konto - logowanie");
    do
    {
        header.render();
        loginInput.render();
        login = loginInput.get();
        passwordInput.render();
        password = passwordInput.get();
        try
        {
            this->account = BankAccount::login(login, password);
            done = true;
        }
        catch (const except::FileNotFound &e)
        {
            ErrorView error(this->output, "W systemie nie ma jeszcze zadnego konta.");
            error.render();
            done = true;
            passwordInput.pressToContinue();
        }
        catch (const except::BadCredentials &e)
        {
            ErrorView error(this->output, "Podane dane sa nieprawidlowe.");
            error.render();
            tryAgain.render();
            done = !tryAgain.get();
        }
    } while (!done);
}

void BankAccountController::logout()
{
    if (this->account != nullptr)
    {
        delete this->account;
        this->account = nullptr;
    }
}

BankAccountController::~BankAccountController()
{
    this->logout();
}