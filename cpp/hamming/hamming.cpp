#include "hamming.h"

#include <algorithm>
#include <iostream>
#include <c++/stdexcept>

namespace hamming
{
unsigned compute(const std::string& sequence_1, const std::string& sequence_2)
{
    if (sequence_1.size() != sequence_2.size())
    {
        throw std::domain_error("Sequences are not of same length");
    }

    auto hamming_distance = 0u;
    for (auto i = 0; i != sequence_1.size(); ++i)
    {
        hamming_distance += (sequence_1.at(i) == sequence_2.at(i)) ? 0 : 1;
    }

    return hamming_distance;
}
}