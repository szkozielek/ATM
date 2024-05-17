#include "TooLargeAmount.h"

const char * except::TooLargeAmount::what() const noexcept {
    return "Too large amount - infinity or out of specified range";
}