//
// Created by mike on 8/2/17.
//

#ifndef PHONE_NUMBER_PHONE_NUMBER_H
#define PHONE_NUMBER_PHONE_NUMBER_H

#include <string>

class phone_number {

public:
    explicit phone_number(const char* number);

    std::string number() const;

    std::string area_code() const;

    explicit operator std::string() const;

private:
    std::string exchange_code() const;

    std::string subscriber_number() const;

    std::string m_number;
};


#endif //PHONE_NUMBER_PHONE_NUMBER_H
