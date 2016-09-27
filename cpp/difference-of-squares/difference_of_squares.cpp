#include "difference_of_squares.h"
#include <algorithm>
#include <functional>

namespace squares
{

    namespace
    {
        uint64_t generate_numbers_and_sum_up (uint32_t number_of_natural_numbers,
                                              std::function<uint32_t (uint32_t)> fnc)
        {
            std::vector<uint32_t> numbers(number_of_natural_numbers - 1);
            uint32_t n = 1;
            std::generate(numbers.begin(), numbers.end(), [&n, fnc] { return fnc(++n); });
            return std::accumulate(std::begin(numbers), std::end(numbers), 1u);
        }

    }

    uint64_t square_of_sums (uint32_t number_of_natural_numbers)
    {
        const auto sum = generate_numbers_and_sum_up(number_of_natural_numbers,
                                                     [] (uint32_t n) { return n; });
        return sum * sum;
    }

    uint64_t sum_of_squares (uint32_t number_of_natural_numbers)
    {
        return generate_numbers_and_sum_up(number_of_natural_numbers,
                                           [] (uint32_t n) { return n * n; });
    }

    uint64_t difference (uint32_t number_of_natural_numbers)
    {
        return square_of_sums(number_of_natural_numbers) - sum_of_squares(number_of_natural_numbers);
    }
};
