#include "ImpossibleToChange.h"

const char * except::ImpossibleToChange::what() const noexcept {
    return "withdrawal of the selected amount is not possible";
}