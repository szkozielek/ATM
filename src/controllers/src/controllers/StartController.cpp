#include "StartController.h"

StartController::StartController(
    const GetEnv *const config,
    std::istream *const in,
    std::ostream *const out
) : Controller(config, in, out)
{

}

void StartController::cover()
{
    layout::show<layout::Cover>(this->output);
    this->input->get();
    this->input->clear();
}

void StartController::index()
{
    std::string selectedOption = "";
    SelectOptionView select(this->input, this->output, "Co chcesz dzisiaj zrobic?", {
        // {"1", "Odbierz nowa karte"}, 
        {"2", "Wyplac pieniadze"}, 
        {"3", "Wplac pieniadze"}, 
        {"q", "Zakoncz prace"}
    });
    
    std::set<std::string> atmOptions = {"2", "3"};
    do
    {
        select.render();
        selectedOption = smartstring::lower(select.select());
        if (atmOptions.find(selectedOption) != atmOptions.end())
        {
            ATMController *ctrElement = new ATMController(this->config, this->input, this->output);
            // if (selectedOption == "1")
            // {
            //     ctrElement->create();
            // }
            if (selectedOption == "2")
            {
                ctrElement->getCash();
            }
            else if (selectedOption == "3"){
                ctrElement->insertCash();
            }
            delete ctrElement;
        }
    } while (selectedOption != "q");
    
}