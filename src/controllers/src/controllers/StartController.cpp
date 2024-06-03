#include "StartController.h"

StartController::StartController(
    const GetEnv *const config,
    std::istream *const in,
    std::ostream *const out) : Controller(config, in, out)
{
}

void StartController::index()
{
    ATMController *atmCtrl;
    BankController *bankCtrl;
    std::string selectedOption = "";
    SelectOptionView select(this->input, this->output, "Co chcesz dzisiaj zrobic?", {{"1", "Uzyj bankomatu"}, {"2", "Zarzadzanie kontem"}, {"q", "Zakoncz prace"}});
    layout::show<layout::Cover>(this->output);
    this->input->get();
    this->input->clear();
    do
    {
        select.render();
        selectedOption = smartstring::lower(select.select());
        if (selectedOption == "1")
        {
            atmCtrl = new ATMController(this->config, this->input, this->output);
            atmCtrl->index();
            delete atmCtrl;
        }
        else if (selectedOption == "2")
        {
            bankCtrl = new BankController(this->config, this->input, this->output);
            bankCtrl->index();
            delete bankCtrl;
        }
    } while (selectedOption != "q");
}