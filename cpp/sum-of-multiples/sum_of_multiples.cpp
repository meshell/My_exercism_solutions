#include "sum_of_multiples.h"

#include <algorithm>
#include <numeric>
#include <functional>

namespace {

template<typename T>
inline bool is_multiple_of_any(T value, const std::vector<T>& multiples) {
    const auto multiple_of = [value](const T mult) {
        return value % mult == 0;
    };
    return std::any_of(std::begin(multiples),
                       std::end(multiples),
                       multiple_of);
}
}

namespace sum_of_multiples {

unsigned to(std::vector<unsigned> multiples, unsigned limit) {

    const auto multiple_of_any = [&multiples](const auto& v) {
        return is_multiple_of_any(v, multiples);
    };
    unsigned sum = 0;
    for (unsigned i = 0; i < limit; ++i){
        sum += multiple_of_any(i) ? i : 0;
    }

    return sum;
}
};