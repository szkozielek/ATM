#include "Hash.h"

unsigned long long hash::defaultHashFunction(const std::string & toHash)
{
    unsigned long long result = 0, mask = 9223372036854775807;
    std::vector<unsigned long long> weight = {1123, 532, 3121, 22, 69123091, 191919, 5232323, 91212222, 11123213, 3, 2137};
    std::string::const_iterator iter;
    for(iter = toHash.begin(); iter != toHash.end(); iter++){
        unsigned long long temp = 0;
        temp = mask - ( *iter * weight[ std::distance(toHash.begin(), iter) % 11 ] );
        temp = temp & mask;
        result = ((result + temp) & mask) | 4611686018427387904;
    }
    return result;
}

unsigned long long hash::generate(const std::string & toHash, unsigned long long (*fnc)(const std::string &))
{
    return fnc(toHash);
}