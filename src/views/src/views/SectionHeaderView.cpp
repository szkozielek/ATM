#include "SectionHeaderView.h"

SectionHeaderView::SectionHeaderView(std::ostream *const output, const std::string &label) : View(nullptr, output), label(label)
{
}

void SectionHeaderView::render()
{
    menu::clearScreen(*this->output);
    layout::show<layout::Header>(this->output, this->label);
}