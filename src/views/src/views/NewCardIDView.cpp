#include "NewCardIDView.h"

NewCardIDView::NewCardIDView(std::istream *const input, std::ostream *const output) : View(input, output)
{
}

void NewCardIDView::render()
{
    *this->output << "Twoj numer karty:\t" << colors::yellow << cardID << colors::white << std::endl;
}