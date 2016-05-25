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
    if ((lhs_all_lower != rhs_all_lower) &&
        (lhs_all_lower.size() == rhs_all_lower.size()))
    {
        std::sort(std::begin(lhs_all_lower), std::end(lhs_all_lower));
        std::sort(std::begin(rhs_all_lower), std::end(rhs_all_lower));
        return (lhs_all_lower == rhs_all_lower);
    }
    return false;
}
}

anagram::anagram (const std::string & str)
    : init_str{str}
{
}

anagram::anagram_list_t anagram::matches (anagram::anagram_list_t canditates) const
{
    anagram_list_t anagrams;

    std::copy_if(canditates.cbegin(),
                 canditates.cend(),
                 std::back_inserter(anagrams),
                 [&] (const std::string & candidate)
                 {
                     return is_anagram_of(candidate, init_str);
                 });
    return anagrams;
}

}