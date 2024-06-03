#include "InsertCashView.h"

InsertCashView::InsertCashView(std::istream *const input, std::ostream *const output, const std::string &currency) : View(input, output), currency(currency)
{
}

void InsertCashView::render()
{
    std::set<std::string>::iterator iter;
    menu::clearScreen(*this->output);

    *this->output << colors::red;
    *this->output << std::endl
                  << colors::white << "Aby zakonczyc wplacanie, wprowadz znak \"" << colors::yellow << "q" << colors::white << "\"" << std::endl
                  << colors::red;
    menu::line(*this->output, 42);
    *this->output << std::endl
                  << colors::white;

    if (this->cash > 0)
    {
        *this->output << std::endl;
        menu::line(*this->output, 42);
        *this->output << std::endl
                      << "Aktualnie wplacono:" << colors::green << std::setw(23) << this->cash << this->currency << colors::white << std::endl;
        menu::line(*this->output, 42);
        *this->output << std::endl;
    }

    for (iter = this->errors.begin(); iter != this->errors.end(); ++iter)
    {
        layout::show<layout::ValidateError>(this->output, *iter);
    }

    *this->output << std::endl
                  << "Wprowadz banknoty do wplatomatu (format: " << colors::yellow << "nominal|ilosc" << colors::white << "):" << std::endl
                  << std::endl;
}

std::string InsertCashView::insert()
{
    std::string cash;
    this->clearErrors();
    *this->output << colors::yellow;
    *this->input >> cash;
    *this->output << colors::white;

    return cash;
}