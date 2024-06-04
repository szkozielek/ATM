#include "CoverView.h"

CoverView::CoverView(std::istream *const input, std::ostream *const output) : View(input, output)
{
}

void CoverView::render()
{
    layout::show<layout::Cover>(this->output);
}

void CoverView::pressToContinue()
{
    this->input->get();
    this->input->clear();
}