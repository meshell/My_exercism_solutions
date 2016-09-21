#ifndef LEAP_LEAP_H_H
#define LEAP_LEAP_H_H

#include <cstdint>

namespace leap
{
    bool is_leap_year (uint32_t year)
    {
        return (year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0);
    }
}

#endif //LEAP_LEAP_H_H
