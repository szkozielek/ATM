#pragma once
#include <vector>
#include <string>
#include <iterator>
#include <cmath>

#include <iostream>

namespace hash
{
    unsigned long long defaultHashFunction(const std::string &);
    unsigned long long generate(const std::string &, unsigned long long (*)(const std::string &) = defaultHashFunction);
}