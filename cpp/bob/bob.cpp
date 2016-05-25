#include "bob.h"
#include <locale>
#include <algorithm>

namespace bob
{
std::string hey (const std::string& text)
{
    auto text_without_whitespace = text;
    text_without_whitespace.erase(std::remove(std::begin(text_without_whitespace),
                                              std::end(text_without_whitespace), ' '),
                                  std::end(text_without_whitespace));
    if (text_without_whitespace.empty())
    {
        return "Fine. Be that way!";
    }

    auto text_with_all_alpha = text_without_whitespace;
    text_with_all_alpha.erase(std::remove_if(std::begin(text_with_all_alpha),
                                             std::end(text_with_all_alpha),
                                             [](const char& c){
                                                 return not isalpha(c);
                                             }),
                              std::end(text_with_all_alpha));

    if (not text_with_all_alpha.empty())
    {
        const auto is_all_upper = std::all_of(text_with_all_alpha.cbegin(),
                                              text_with_all_alpha.cend(),
                                              [](const char& c){
                                                  return (isupper(c));
                                              });
        if (is_all_upper)
        {
            return "Whoa, chill out!";
        }
    }
    if (text_without_whitespace.back() == '?')
    {
        return "Sure.";
    }
    return "Whatever.";
}

}