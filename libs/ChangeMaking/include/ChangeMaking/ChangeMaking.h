#pragma once
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
#include "TooLargeAmount.h"
#include "ImpossibleToChange.h"


namespace changemaking{
    extern unsigned int infinity;

    std::map<unsigned int, unsigned int> getCash(const std::map<unsigned int, unsigned int> &, unsigned int );

    void __checkAmountForCurrentCash(unsigned int ***, const std::map<unsigned int, unsigned int>::const_iterator &, unsigned int, unsigned int);
    unsigned int *** __createCashTable(size_t, size_t);
    void __freeCashTable(unsigned int ***, size_t, size_t);
    void __showTable(unsigned int ***, const std::map<unsigned int, unsigned int> &, size_t);

}