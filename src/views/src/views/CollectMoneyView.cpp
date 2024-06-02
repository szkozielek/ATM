#include "CollectMoneyView.h"

CollectMoneyView::CollectMoneyView(std::istream * const input, std::ostream * const output, const std::string & label) : View(input, output), label(label)
{

}

void CollectMoneyView::render()
{
    std::map<unsigned int, unsigned int>::iterator iter;
    *this->output << colors::green;
    menu::line(*this->output, 70);
    *this->output << std::endl << this->label << std::endl;
    menu::line(*this->output, 70);
    *this->output << colors::white << std::endl;
    for (iter = cash.begin(); iter != cash.end(); ++iter)
    {
        *this->output << colors::yellow << std::setw(15) << iter->first << this->currency << colors::white << " => " << colors::green << iter->second << std::endl;
    }
    *this->output << colors::green;
    menu::line(*this->output, 70);
    *this->output << std::endl << colors::white;
}

void CollectMoneyView::render(const std::string &error)
{
    ErrorView errorView(this->output, error);
    errorView.render();
}