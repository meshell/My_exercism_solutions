#include "bob.h"
#include <locale>
#include <algorithm>

namespace {
bool is_silent(std::string text)
{
    text.erase(std::remove(std::begin(text),
                           std::end(text), ' '),
               std::end(text));
    return text.empty();
}

bool is_yelling(std::string text)
{
    text.erase(std::remove_if(std::begin(text),
                              std::end(text),
                              [](const char& c){
                                  return not isalpha(c);
                              }),
               std::end(text));
    return ((not text.empty()) &&
            (std::all_of(text.cbegin(),
                         text.cend(),
                         [](const char& c){
                             return (isupper(c));
                         })));
}

bool is_question(std::string text)
{
    const auto last_question_mark = text.find_last_of('?');
    return ((last_question_mark != std::string::npos) &&
            (last_question_mark >= text.find_last_not_of(' ')));
}
}


namespace bob
{
std::string hey (const std::string& text)
{
    if (is_silent(text)) {
        return "Fine. Be that way!";
    }
    if (is_yelling(text)) {
        return "Whoa, chill out!";
    }
    if (is_question(text)) {
        return "Sure.";
    }
    return "Whatever.";
}

}