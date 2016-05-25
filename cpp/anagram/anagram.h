#ifndef ANAGRAM_ANAGRAM_H
#define ANAGRAM_ANAGRAM_H

#include <string>
#include <vector>

namespace anagram
{

class anagram
{
public:
    using anagram_list_t = std::vector<std::string>;

    anagram (const std::string &str);
    anagram_list_t matches (anagram_list_t possible_anagrams) const;

private:
    std::string init_str;
};

}

#endif //ANAGRAM_ANAGRAM_H