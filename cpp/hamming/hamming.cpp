#include "hamming.h"

#include <algorithm>
#include <stdexcept>

namespace hamming
{
unsigned compute(const std::string& sequence_1, const std::string& sequence_2)
{
    if (sequence_1.size() != sequence_2.size())
    {
        throw std::domain_error("Sequences are not of same length");
    }
    return std::inner_product(sequence_1.cbegin(), sequence_1.cend(), sequence_2.cbegin(), 0,
                              std::plus<char>(), std::not_equal_to<char>());
}
}