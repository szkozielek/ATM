#include "BallanceView.h"

BallanceView::BallanceView(std::istream *const input, std::ostream *const output) : View(input, output)
{
}

void BallanceView::setBallance(const std::map<std::string, unsigned long long> &ballance)
{
    this->ballance = ballance;
}

void BallanceView::render()
{
    std::map<std::string, unsigned long long>::iterator iter;
    for (iter = this->ballance.begin(); iter != this->ballance.end(); ++iter)
    {
        *this->output << iter->first << " => " << colors::yellow << std::setw(11) << iter->second << colors::white << std::endl;
    }
}