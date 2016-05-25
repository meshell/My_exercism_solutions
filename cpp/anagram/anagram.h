#ifndef ANAGRAM_ANAGRAM_H
#define ANAGRAM_ANAGRAM_H

#include <string>
#include <vector>
#include <memory>

namespace anagram
{

class anagram
{
public:
    using anagram_list_t = std::vector<std::string>;

    anagram (const std::string & str);
    ~anagram ();
    anagram (anagram &&);
    anagram & operator= (anagram &&);

    anagram_list_t matches (anagram_list_t possible_anagrams) const;

private:
    class anagram_impl;
    std::unique_ptr<anagram_impl> pimpl;
};

}

#endif //ANAGRAM_ANAGRAM_H