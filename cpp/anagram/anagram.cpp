#include "anagram.h"
#include <algorithm>
#include <numeric>
#include <boost/algorithm/string.hpp>

namespace anagram
{

namespace
{

bool is_anagram_of (const std::string & lhs, const std::string & rhs)
{
    auto lhs_all_lower = boost::to_lower_copy(lhs);
    auto rhs_all_lower = boost::to_lower_copy(rhs);

    std::sort(std::begin(lhs_all_lower), std::end(lhs_all_lower));
    std::sort(std::begin(rhs_all_lower), std::end(rhs_all_lower));

    return (lhs_all_lower == rhs_all_lower);
}
}

anagram::anagram (const std::string & str)
    : init_str{str}
{

}

anagram::anagram_list_t anagram::matches (anagram::anagram_list_t possible_anagrams) const
{
    return std::accumulate(possible_anagrams.cbegin(),
                           possible_anagrams.cend(),
                           anagram_list_t{},
                           [&] (anagram_list_t result, const std::string & possible_anagram)
                           {
                               if ((boost::to_lower_copy(possible_anagram) != boost::to_lower_copy(init_str)) &&
                                   is_anagram_of(possible_anagram, init_str))
                               {
                                   result.emplace_back(possible_anagram);
                               }
                               return result;
                           });
}

}