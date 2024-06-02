#include "ConfirmView.h"

ConfirmView::ConfirmView(std::istream * const input, std::ostream * const output, const std::string &label) : View(input, output), label(label)
{

}

void ConfirmView::render()
{
    *this->output << this->label << " (" << colors::yellow << "tak" << colors::white << "/" << colors::yellow << "nie" << colors::white << "): ";
}

bool ConfirmView::get()
{
    std::string selectedOption;
    *this->output << colors::yellow;
    *this->input >> selectedOption;
    *this->output << colors::white << std::endl;
    selectedOption = smartstring::lower(selectedOption);
    
    return selectedOption == "t" || selectedOption == "tak";
}