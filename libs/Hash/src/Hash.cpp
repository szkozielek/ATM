#include "Hash.h"

unsigned long long hash::defaultHashFunction(const std::string &toHash)
{
    unsigned long long result = 0, mask = 9223372036854775807;
    std::vector<unsigned long long> weight = {
        932436382738, 11235, 72323893284938329,
        5321, 69123091, 91212222, 1115232513,
        2948473983920384, 2137, 18237392832,
        22, 3482823723821, 3, 82364738283839, 191919,
        194803382729000328, 5232323, 628398349182492, 1113371111111775807};
    std::string::const_iterator iter;
    for (iter = toHash.begin(); iter != toHash.end(); iter++)
    {
        unsigned long long temp = 0;
        temp = mask - (*iter * weight[std::distance(toHash.begin(), iter) % weight.size()]);
        temp = temp & mask;
        result = ((result + temp) & mask) | 4611686018427387904;
    }
    return result;
}

unsigned long long hash::generate(const std::string &toHash, unsigned long long (*fnc)(const std::string &))
{
    return fnc(toHash);
}