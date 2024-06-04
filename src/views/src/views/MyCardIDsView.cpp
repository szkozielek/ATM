#include "MyCardIDsView.h"

MyCardIDsView::MyCardIDsView(std::istream *const input, std::ostream *const output, const std::set<std::string> &cardIDs) : View(input, output), cardIDs(cardIDs)
{
}

void MyCardIDsView::render()
{
    std::set<std::string>::iterator iter;

    if (this->cardIDs.size() > 0)
    {
        menu::line(*this->output, 40) << std::endl;
        for (iter = this->cardIDs.begin(); iter != this->cardIDs.end(); ++iter)
        {
            *this->output << colors::white << "\t" << std::distance(this->cardIDs.begin(), iter) + 1 << ". " << colors::yellow << *iter << colors::white << std::endl;
        }
        menu::line(*this->output, 40) << colors::white << std::endl;
    }
    else
    {
        ErrorView error(this->output, "Nie dodano zadnej karty do konta.");
        error.render();
    }
}