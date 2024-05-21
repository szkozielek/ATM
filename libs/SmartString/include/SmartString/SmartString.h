#pragma once
#include <string>
#include <cctype>
#include <algorithm>

namespace smartstring
{
    std::string transform(const std::string &, int (*)(int));
    std::string lower(const std::string &);
    std::string upper(const std::string &);
}