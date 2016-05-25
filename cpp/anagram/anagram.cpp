#include "anagram.h"
#include <algorithm>
#include <numeric>
#include <utility>
#include <boost/algorithm/string.hpp>

namespace
{

template<typename T>
T sort (T container)
{
    using std::begin;
    using std::end;
    std::sort(begin(container), end(container));
    return container;
}

template<typename T, typename Func>
T filter (const T & container, Func && filter_func)
{
    T out;
    std::copy_if(container.cbegin(),
                 container.cend(),
                 std::back_inserter(out),
                 filter_func
    );
    return out;
}

template<typename T, typename ...Args>
std::unique_ptr<T> make_unique (Args && ...args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
}

namespace anagram
{

class anagram::anagram_impl
{
public:
    anagram_impl (const std::string & base)
        : base_str{base}
    {
    }

    bool is_anagram (const std::string & candidate)
    {
        const auto base_all_lower = boost::to_lower_copy(base_str);
        const auto candidate_all_lower = boost::to_lower_copy(candidate);
        if ((base_all_lower != candidate_all_lower) &&
            (base_all_lower.size() == candidate_all_lower.size()))
        {
            return (sort(std::move(base_all_lower)) == sort(std::move(candidate_all_lower)));
        }
        return false;
    }

private:
    const std::string base_str;
};

anagram::anagram (const std::string & base)
    : pimpl{make_unique<anagram_impl>(base)}
{
}

anagram::anagram_list_t anagram::matches (anagram::anagram_list_t canditates) const
{
    return filter(canditates,
                  [this] (const std::string & candidate)
                  {
                      return pimpl->is_anagram(candidate);
                  });
}

anagram::~anagram () = default;
anagram::anagram (anagram &&) = default;
anagram & anagram::operator= (anagram &&) = default;

}