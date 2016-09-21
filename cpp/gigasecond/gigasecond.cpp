#include "gigasecond.h"

namespace gigasecond
{
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    date advance(date date_of_birth)
    {
        const auto gigaseconds = seconds(1000000000);
        return ptime{date_of_birth, gigaseconds}.date();
    }
}
