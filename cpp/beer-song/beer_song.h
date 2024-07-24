#if !defined(BEER_SONG_H)
#define BEER_SONG_H

#include <string>

namespace beer_song {

std::string verse(unsigned bootles);

std::string sing(unsigned start_bootles, unsigned end_bootles = 0);

} // namespace beer_song

#endif // BEER_SONG_H