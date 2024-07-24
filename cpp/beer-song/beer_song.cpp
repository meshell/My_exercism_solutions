#include "beer_song.h"

namespace beer_song {

std::string verse(unsigned bootles) {
  if (bootles == 0) {
    return "No more bottles of beer on the wall, no more bottles of beer.\nGo "
           "to the store and buy some more, 99 bottles of beer on the wall.\n";
  } else {
    const auto bottle_text = [](unsigned bottles) -> std::string {
      if (bottles == 0) {
        return std::string{"no more bottles"};
      }
      return std::to_string(bottles) + (bottles == 1 ? " bottle" : " bottles");
    };

    const std::string line_1 = bottle_text(bootles) + " of beer on the wall, " +
                               bottle_text(bootles) + " of beer.\n";
    const std::string line_2 =
        std::string{"Take "} + (bootles == 1 ? "it" : "one") +
        " down and pass it around, " + bottle_text(bootles - 1) +
        " of beer on the wall.\n";
    return line_1 + line_2;
  }
}

std::string sing(unsigned start_bootles, unsigned end_bootles) {
  std::string song_verses{};
  for (auto i = start_bootles; i > end_bootles; --i) {
    song_verses += verse(i) + "\n";
  }
  return song_verses + verse(end_bootles);
}

} // namespace beer_song
