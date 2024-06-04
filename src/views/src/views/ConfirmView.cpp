#include "ConfirmView.h"

ConfirmView::ConfirmView(std::istream *const input, std::ostream *const output, const std::string &label) : View(input, output), label(label)
{
}

void ConfirmView::render()
{
    layout::show<layout::Confirm>(this->output, this->label);
}

bool ConfirmView::get()
{
    InputView<std::string> input(this->input, this->output, "");
    std::string selectedOption;
    input.render();
    selectedOption = input.get();

    selectedOption = smartstring::lower(selectedOption);

    return selectedOption == "t" || selectedOption == "tak";
}