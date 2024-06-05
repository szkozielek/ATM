#include "BankController.h"

BankController::BankController(const GetEnv *const config, std::istream *const input, std::ostream *const output) : Controller(config, input, output)
{
}

void BankController::index()
{
    std::string selectedOption = "";
    BankAccountController accountCtrl(this->config, this->input, this->output);
    SelectOptionView select(this->input, this->output, "Wybierz opcje:", {{"1", "Zaloguj"}, {"2", "Nowe konto"}, {"q", "Powrot"}});
    SectionHeaderView header(this->output, "Konta bankowe");
    do
    {
        header.render();
        select.render();
        selectedOption = smartstring::lower(select.select());
        if (selectedOption == "1")
        {
            accountCtrl.index();
                }
        else if (selectedOption == "2")
        {
            accountCtrl.create();
        }
    } while (selectedOption != "q");
}