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

    std::string lower_case_phrase;
    std::transform(phrase.cbegin(),
                   phrase.cend(),
                   std::back_inserter(lower_case_phrase),
                   [](const char& c) { return std::tolower(c);});

    boost::split(strings, lower_case_phrase, ((not boost::is_any_of("'") && boost::is_punct()) || boost::is_space()));
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
            auto elementExists = result.find(str);
            if (elementExists != std::end(result))
            {
                elementExists->second += 1;
            }
            else
            {
                result.emplace(std::make_pair(str, 1));
            }
        }
    }
    return result;
};
}