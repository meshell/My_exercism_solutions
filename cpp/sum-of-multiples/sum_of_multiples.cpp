#include "sum_of_multiples.h"

#include <algorithm>
#include <numeric>
#include <functional>
#include <set>

namespace {

template<typename T>
std::set<T> generate_multiples(std::vector<T> multiples,
                                              T limit) {
    std::set<T> sequence;
    for (const auto multiple: multiples) {
        for (auto i = multiple; i < limit; i += multiple) {
            sequence.insert(i);
        }
    }
    return sequence;
}

}
namespace sum_of_multiples {

unsigned to(std::vector<unsigned> multiples, unsigned limit) {

    const auto all_multiples = generate_multiples(multiples, limit);
    return std::accumulate(std::begin(all_multiples),
                           std::end(all_multiples),
                           0,
                           std::plus<unsigned>());
}
};