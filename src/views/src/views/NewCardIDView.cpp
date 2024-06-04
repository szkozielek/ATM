#include "NewCardIDView.h"

NewCardIDView::NewCardIDView(std::istream *const input, std::ostream *const output) : View(input, output)
{
}

void NewCardIDView::render()
{
    *this->output << colors::green;
    menu::line(*this->output, 40) << colors::white << std::endl;
    *this->output << "Twoj numer karty:\t" << colors::yellow << cardID << colors::green << std::endl;
    menu::line(*this->output, 40) << colors::white << std::endl;
}