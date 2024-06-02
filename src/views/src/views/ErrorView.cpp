#include "ErrorView.h"

ErrorView::ErrorView(std::ostream * const output, const std::string & error) : View(nullptr, output), error(error)
{

}

void ErrorView::render()
{
    *this->output << colors::red;
    menu::line(*this->output, 70);
    *this->output << std::endl << this->error << std::endl;
    menu::line(*this->output, 70);
    *this->output << std::endl << colors::white << std::endl;
}