#include "bob.h"
#include <regex>

namespace {
bool is_silent(const std::string& text)
{
    return std::regex_match(text, std::regex{"[[:space:]]*"});
}

bool is_yelling(const std::string& text)
{
    const auto text_with_only_letters = std::regex_replace(text, std::regex{"[^[:alpha:]]"}, "");
    return std::regex_match(text_with_only_letters, std::regex{"[[:upper:]]+"});
}

bool is_question(const std::string& text)
{
    return std::regex_match(text, std::regex{".*[?][[:space:]]*"});
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