#pragma once

#include <string>
#include <tuple>

#include "PhoneNumber.h"

class Person
{
private:
    std::string _first_name;
    std::string _last_name;
    PhoneNumber _phone_number;

public:
    Person(std::string first_name, std::string last_name);
    Person(std::string first_name, std::string last_name, PhoneNumber phone_number);

    std::string get_full_name() const;
    std::string get_last_name() const;
    PhoneNumber get_phone_number() const;

    void set_phone_number(PhoneNumber);

    bool operator< (const Person&);
};

Person::Person(std::string first_name, std::string last_name):
    Person{ first_name, last_name, PhoneNumber{-1,-1,-1,-1,-1} }
{}

Person::Person(std::string first_name, std::string last_name, PhoneNumber phone_number):
    _first_name { first_name },
    _last_name { last_name },
    _phone_number { phone_number }
{}

std::string Person::get_full_name() const
{
    return _first_name + " " + _last_name;
}

std::string Person::get_last_name() const
{
    return _last_name;
}

PhoneNumber Person::get_phone_number() const
{
    return _phone_number;
}

void Person::set_phone_number(PhoneNumber phone_number)
{
    _phone_number = phone_number;
}

bool Person::operator< (const Person& p)
{
    auto val1 = std::tie(_last_name, _first_name);
    auto val2 = std::tie(p._last_name, p._first_name);
    return val1 < val2;
}
