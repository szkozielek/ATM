#pragma once
#include <iostream>
#include <limits>

class View
{
protected:
    std::istream *const input;
    std::ostream *const output;
    View(std::istream *const, std::ostream *const);

public:
    View() = delete;
    virtual void render() = 0;
    void pressToContinue();
};