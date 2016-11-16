#ifndef NUCLEOTIDE_COUNT_NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_NUCLEOTIDE_COUNT_H

#include <string>
#include <map>
#include <algorithm>
#include <exception>

namespace dna
{
    class counter
    {
    public:
        explicit counter (const std::string& dna)
                : counter_map{}
        {
            for (const auto& nucleotide : {'A', 'T', 'C', 'G'}) {
                counter_map[nucleotide] = count_nucleotide_in_dna(dna, nucleotide);
            }
        }

        std::map<char, int> nucleotide_counts () const
        {
            return counter_map;
        }

        int count (char nucleotide) const
        {
            if (counter_map.count(nucleotide) == 0) {
                throw std::invalid_argument{nucleotide + " is not a nucleotide"};
            }
            return counter_map.at(nucleotide);
        }

    private:
        int count_nucleotide_in_dna(const std::string& dna, char nucleotide) const
        {
            return std::count(dna.cbegin(), dna.cend(), nucleotide);
        }
        std::map<char, int> counter_map;
    };
}
#endif //NUCLEOTIDE_COUNT_NUCLEOTIDE_COUNT_H
