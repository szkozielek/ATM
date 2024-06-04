#include "SelectOptionView.h"

SelectOptionView::SelectOptionView(std::istream *const in, std::ostream *const out, const std::string &label, const std::map<std::string, std::string> &options) : View(in, out), options(options), label(label)
{
}

void SelectOptionView::standardValidation(const std::string &selectedOption)
{
    if (selectedOption != "" && (this->options.find(selectedOption) == this->options.end()))
    {
        this->addError("Wybierz element z listy");
    }
}

void SelectOptionView::render()
{
    std::set<std::string>::iterator iter;
    *this->output << this->label << std::endl;
    for (iter = this->errors.begin(); iter != this->errors.end(); ++iter)
    {
        layout::show<layout::ValidateError>(this->output, *iter);
    }
    *this->output << std::endl;
    layout::show<layout::Select>(this->output, options);
}

std::string SelectOptionView::select()
{
    std::string selectedOption;
    this->clearErrors();
    *this->input >> selectedOption;
    this->standardValidation(selectedOption);
    return selectedOption;
}