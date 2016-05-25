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
    auto it_seq1 = sequence_1.cbegin();
    auto it_seq2 = sequence_2.cbegin();
    auto count = 0u;
    while (it_seq1 != sequence_1.cend())
    {
        const auto mismatch_it = std::mismatch(it_seq1, sequence_1.cend(), it_seq2);
        it_seq1 = mismatch_it.first;
        it_seq2 = mismatch_it.second+1;
        if (it_seq1 != sequence_1.cend())
        {
            ++count;
            ++it_seq1;
        }
    }
    return count;
}
}