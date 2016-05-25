#include "anagram.h"
#include <algorithm>
#include <numeric>
#include <boost/algorithm/string.hpp>

namespace anagram
{

anagram::anagram (const std::string &str)
    : init_str{boost::to_lower_copy(str)}
{
}

anagram::anagram_list_t anagram::matches (anagram::anagram_list_t possible_anagrams) const
{
    return std::accumulate(possible_anagrams.cbegin(),
                           possible_anagrams.cend(),
                           anagram_list_t{},
                           [&] (anagram_list_t result, const std::string &possible_anagram)
                           {
                               const auto as_all_lowercase = boost::to_lower_copy(possible_anagram);
                               if ((as_all_lowercase != init_str) &&
                                   std::is_permutation(as_all_lowercase.cbegin(),
                                                       as_all_lowercase.cend(),
                                                       init_str.cbegin()))
                               {
                                   result.emplace_back(possible_anagram);
                               }
                               return result;
                           });
}

}