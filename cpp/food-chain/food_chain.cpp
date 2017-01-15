#include "food_chain.h"

#include <vector>

namespace food_chain
{

static const std::vector<std::string> animals = {{
                                                     "fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"
                                                 }};

std::string verse (size_t line)
{
    static const std::vector<std::string> verse_lines = {{
                                                             "",
                                                             "",
                                                             "It wriggled and jiggled and tickled inside her.\n",
                                                             "How absurd to swallow a bird!\n",
                                                             "Imagine that, to swallow a cat!\n",
                                                             "What a hog, to swallow a dog!\n",
                                                             "Just opened her throat and swallowed a goat!\n",
                                                             "I don't know how she swallowed a cow!\n",
                                                             "She's dead, of course!\n"
                                                         }};
    auto animal_index = line - 1;
    std::string verse = "I know an old lady who swallowed a " + animals.at(animal_index) + ".\n";
    verse += verse_lines.at(line);

    if (line == animals.size())
    {
        return verse;
    }

    for (auto i = line; i > 1; --i)
    {
        const auto current_animal_idx = i - 1;
        const auto previous_animal_idx = i - 2;
        constexpr auto special_line = 3;
        verse +=
            "She swallowed the " + animals.at(current_animal_idx) + " to catch the " + animals.at(previous_animal_idx) +
            (i == special_line ? " that wriggled and jiggled and tickled inside her" : "") + ".\n";
    }

    return verse + "I don't know why she swallowed the fly. Perhaps she'll die.\n";
}


std::string verses (size_t verse1, size_t verse2)
{
    return verse(verse1) + "\n" + verse(verse2) + "\n";
}

std::string sing ()
{
    return verses(1, animals.size());
}

}