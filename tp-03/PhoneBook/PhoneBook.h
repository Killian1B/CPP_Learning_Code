#pragma once

#include <vector>
#include <string_view>
#include <algorithm>

#include "Person.h"

class PhoneBook
{
private:
    std::vector<Person> _persons;

public:
    const std::vector<Person> get_persons() const;

    bool empty();
    void insert(Person&);
    Person operator[](int index);
    const Person* first_of_family(std::string_view);
    std::vector<Person>::iterator begin();
    std::vector<Person>::iterator end();
};

const std::vector<Person> PhoneBook::get_persons() const
{
    return _persons;
}

bool PhoneBook::empty()
{
    return _persons.empty();
}

void PhoneBook::insert(Person& p)
{
    for(auto i = _persons.begin(); i != _persons.end(); i++)
    {
        if((*i).get_full_name() == p.get_full_name())
        {
            _persons.erase(i);
            break;
        }
    }
    _persons.emplace_back(p);
    std::sort(_persons.begin(), _persons.end()); 
}

Person PhoneBook::operator[](int index)
{
    return _persons.at(index);
}

const Person* PhoneBook::first_of_family(std::string_view name)
{
    for(auto i = _persons.begin(); i != _persons.end(); i++)
    {
        const Person* p = &(*i);
        if((*p).get_last_name() == name)
        {
            return p;
        }
    }
    return nullptr;
}

std::vector<Person>::iterator PhoneBook::begin()
{
    return _persons.begin();
}

std::vector<Person>::iterator PhoneBook::end()
{
    return _persons.end();
}

std::ostream& operator<<(std::ostream& stream, const PhoneBook& p)
{
    auto persons = p.get_persons();
    for(auto i = persons.begin(); i != persons.end(); i++)
    {
        if((*i).get_phone_number().is_valid())
        {
            stream << (*i).get_full_name() << " - " << (*i).get_phone_number() << std::endl;
        }
    }
    return stream;
}