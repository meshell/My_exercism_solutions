//
// Created by mike on 8/2/17.
//

#include "phone_number.h"
#include <regex>

static constexpr auto NUMBER_LENGTH = 10;
static constexpr auto AREA_CODE_IDX = 0;
static constexpr auto AREA_CODE_LENGTH = 3;
static constexpr auto EXCHANGE_CODE_IDX = AREA_CODE_IDX + AREA_CODE_LENGTH;
static constexpr auto EXCHANGE_CODE_LENGTH = 3;
static constexpr auto SUBSCRIBER_NUMBER_IDX = EXCHANGE_CODE_IDX + EXCHANGE_CODE_LENGTH;
static constexpr auto SUBSCRIBER_NUMBER_LENGTH = NUMBER_LENGTH - SUBSCRIBER_NUMBER_IDX;
static constexpr auto INVALID_NUMBER = "0000000000";

phone_number::phone_number(const char* number) {

    m_number = std::regex_replace(number, std::regex(R"([^\d])"), "");
    if ((m_number.size() > NUMBER_LENGTH) && (m_number.at(0) == '1')) {
        m_number.erase(0, 1);
    }
    if (m_number.size() != NUMBER_LENGTH) {
        m_number = INVALID_NUMBER;
    }
}

std::string phone_number::number() const {
    return m_number;
}

std::string phone_number::area_code() const {
    return m_number.substr(AREA_CODE_IDX, AREA_CODE_LENGTH);
}

phone_number::operator std::string() const {
    return "(" + area_code() + ") " + exchange_code() + "-" + subscriber_number();
}

std::string phone_number::exchange_code() const {
    return m_number.substr(EXCHANGE_CODE_IDX, EXCHANGE_CODE_LENGTH);
}

std::string phone_number::subscriber_number() const {
    return m_number.substr(SUBSCRIBER_NUMBER_IDX, SUBSCRIBER_NUMBER_LENGTH);
}
