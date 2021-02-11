#pragma once

#include <iostream>
#include <string>
#include <vector>

class PhoneNumber
{
private:
    std::vector<int> _number;
    int _size_number;

public:
    PhoneNumber(int number1, int number2, int number3, int number4, int number5);

    std::vector<int> get_number() const;

    bool is_valid() const;
};

PhoneNumber::PhoneNumber(int number1, int number2, int number3, int number4, int number5):
    _number { std::vector { number1, number2, number3, number4, number5 } },
    _size_number { 5 }
{}

bool PhoneNumber::is_valid() const
{
    for(int i = 0; i < _size_number; ++i)
    {
        if(_number[i] < 0 || _number[i] > 99)
        {
            return false;
        }
    }
    return true;
}

std::vector<int> PhoneNumber::get_number() const
{
    return _number;
}

std::string num_to_string(int num)
{
    if(num < 10)
    {
        return "0" + std::to_string(num);
    }
    return std::to_string(num);
}

std::ostream& operator<<(std::ostream& stream, const PhoneNumber& p)
{
    auto num = p.get_number();
    for(auto i = num.begin(); i != num.end()-1; i++)
    {
        stream << num_to_string(*i) << " ";
    }
    stream << num_to_string(*(num.end()-1));
    return stream;
}