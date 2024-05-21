#include "StartController.h"

StartController::StartController(
    const GetEnv *const config,
    std::istream *const in,
    std::ostream *const out) : Controller(config, in, out) {}

void StartController::cover()
{
    layout::show<layout::Cover>(this->output);
    this->input->get();
}

void StartController::index()
{
    std::string selectedOption = "";
    std::set<std::string> bankAccountOptions = {"1", "2", "3"};
    std::map<std::string, std::string> options = {{"1", "Zaloz konto"}, {"2", "Wyplac pieniadze"}, {"3", "Wplac pieniadze"}, {"q", "Zakoncz prace"}};
    do
    {
        menu::clearScreen(*this->output);
        *this->output << "Co chcesz dzisiaj zrobic?" << std::endl;
        if (selectedOption != "" && (options.find(selectedOption) == options.end()))
        {
            layout::show<layout::ValidateError>(this->output, "Wybierz element z listy");
        }
        *this->output << std::endl;
        layout::show<layout::Select>(this->output, options);
        *this->input >> selectedOption;
        selectedOption = smartstring::lower(selectedOption);
        if (bankAccountOptions.find(selectedOption) != bankAccountOptions.end())
        {
            BankAccountController *ctrElement = new BankAccountController(this->config, this->input, this->output);
            if (selectedOption == "1")
            {
                ctrElement->create();
            }
            else if (selectedOption == "2")
            {
                ctrElement->getCash();
            }
            delete ctrElement;
        }
    } while (selectedOption != "q");
}