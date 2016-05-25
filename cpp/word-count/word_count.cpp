#include "word_count.h"
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>

namespace word_count
{

std::map<std::string, int> words(const std::string& phrase)
{
    std::map<std::string, int> result;
    std::vector<std::string> strings;

    const auto lower_case_phrase = boost::to_lower_copy(phrase);
    boost::split(strings,
                 lower_case_phrase,
                 ((not boost::is_any_of("'") && boost::is_punct()) || boost::is_space()));

    for(auto& str : strings)
    {
        if (str.front() == '\'')
        {
            boost::erase_head(str, 1);
        }
        if (str.back() == '\'')
        {
            boost::erase_tail(str, 1);
        }
        if (not str.empty())
        {
            result[str]++;
        }
    }
    return result;
};
}