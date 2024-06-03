#include "PasswordView.h"

PasswordView::PasswordView(std::istream *const input, std::ostream *const output, const std::string &label) : View(input, output), label(label)
{
}

void PasswordView::render()
{
    this->output->width(15);
    *this->output << this->label;
}

std::string PasswordView::get()
{
    std::string password;
    menu::hideText(*this->output);
    *this->input >> password;
    menu::showText(*this->output);
    *this->output << std::endl;
    return password;
}