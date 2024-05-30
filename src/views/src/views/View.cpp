#include "View.h"

View::View(std::istream * const input, std::ostream * const output) : input(input), output(output)
{

}

void View::pressToContinue()
{
    this->input->ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    this->input->get();
    this->input->clear();
}