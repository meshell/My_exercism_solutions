#include "etl.h"
#include <ctype>

namespace etl
{
    new_score_map_t transform (const old_score_map_t& data)
    {
        new_score_map_t score_map;
        for (const auto& score_entry: data) {
            const auto score = score_entry.first;

            for (const auto& c : score_entry.second) {
                score_map.insert(std::make_pair(std::tolower(c), score));
            }
        }

        return score_map;
    }
}
