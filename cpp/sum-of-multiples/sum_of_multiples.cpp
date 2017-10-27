#include "sum_of_multiples.h"

#include <algorithm>
#include <numeric>
#include <functional>

namespace {

template<typename T, typename Fnc>
std::vector<T> filter(const std::vector<T>& vec, Fnc&& filter_fnc) {
    std::vector<T> filtered;
    std::copy_if(std::begin(vec),
                 std::end(vec),
                 std::back_inserter(filtered),
                 std::forward<Fnc>(filter_fnc));
    return filtered;
};

template<typename T>
bool is_multiple_of_any(T value, const std::vector<T>& multiples) {
    const auto multiple_of = [value](const T mult) {
        return value % mult == 0;
    };
    return std::any_of(std::begin(multiples),
                       std::end(multiples),
                       multiple_of);
}

template<typename T>
std::vector<T> generate_sequence(T limit) {
    std::vector<T> sequence(limit);
    std::iota(std::begin(sequence), std::end(sequence), 0);
    return sequence;
}

}
namespace sum_of_multiples {

unsigned to(std::vector<unsigned> multiples, unsigned limit) {

    const auto multiple_of_any = [&multiples](const auto& v) {
        return is_multiple_of_any(v, multiples);
    };
    const auto all_multiples = filter(generate_sequence(limit),
                                      multiple_of_any);
    return std::accumulate(std::begin(all_multiples),
                           std::end(all_multiples),
                           0,
                           std::plus<unsigned>());
}
};