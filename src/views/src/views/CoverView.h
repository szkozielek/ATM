#pragma once
#include <layout/Cover.h>
#include "View.h"

class CoverView : public View
{
public:
    CoverView(std::istream *const, std::ostream *const);
    void render();
    void pressToContinue();
};