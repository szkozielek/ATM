#include "ErrorView.h"

ErrorView::ErrorView(std::ostream *const output, const std::string &error) : View(nullptr, output), error(error)
{
}

void ErrorView::render()
{
    layout::show<layout::Message>(this->output, this->error, colors::red);
}