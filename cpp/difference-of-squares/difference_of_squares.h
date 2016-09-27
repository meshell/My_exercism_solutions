#ifndef DIFFERENCE_OF_SQUARES_DIFFERENCE_OF_SQUARES_H
#define DIFFERENCE_OF_SQUARES_DIFFERENCE_OF_SQUARES_H

#include <cstdint>

namespace squares
{
    constexpr uint64_t square_of_sums(uint32_t n)
    {
        return n*n*(n+1)*(n+1)/4;
    }

    constexpr uint64_t sum_of_squares(uint32_t n)
    {
        return n*(n+1)*(2*n+1)/6;
    }

    constexpr uint64_t difference(uint32_t n)
    {
        return square_of_sums(n) - sum_of_squares(n);
    }
};


#endif //DIFFERENCE_OF_SQUARES_DIFFERENCE_OF_SQUARES_H
