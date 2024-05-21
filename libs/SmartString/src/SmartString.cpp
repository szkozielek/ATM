#include "SmartString.h"

std::string smartstring::transform(const std::string &str, int (*callback)(int))
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), callback);
    return result;
}

std::string smartstring::lower(const std::string &str)
{
    return smartstring::transform(str, std::tolower);
}

std::string smartstring::upper(const std::string &str)
{
    return smartstring::transform(str, std::toupper);
}
