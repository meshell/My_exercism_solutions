#pragma once

#include <string>
#include <map>
#include <vector>


namespace etl
{
    using new_score_map_t = std::map<char, int>;
    using old_score_map_t = std::map<int, std::vector<char>>;

    new_score_map_t transform (const old_score_map_t& data);
}