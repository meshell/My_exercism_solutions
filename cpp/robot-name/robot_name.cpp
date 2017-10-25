#include "robot_name.h"

#include <random>
#include <algorithm>

namespace {

char generate_random_char(char start, char end) {
    std::random_device rd{};
    auto generator = std::mt19937{rd()};

    auto distribution = std::uniform_int_distribution<char>{start, end};
    return distribution(generator);
}

std::string generate_random_chars(unsigned n, char start, char end) {
    std::string chars = std::string(n, 0);
    std::generate_n(std::begin(chars), n, [=] { return generate_random_char(start, end); });
    return chars;
}

constexpr auto number_of_letters_in_name = 2;
constexpr auto number_of_digits_in_name = 3;

std::string generate_robot_name() {
    return generate_random_chars(number_of_letters_in_name, 'A', 'Z') +
           generate_random_chars(number_of_digits_in_name, '0', '9');
}

}

namespace robot_name {

robot::robot() :
        name_{generate_robot_name()} {

}

std::string robot::name() const {
    return name_;
}

void robot::reset() {
    name_ = generate_robot_name();
}

}
