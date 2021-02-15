#pragma once

#include "Phone.h"

class HomePhone: public Phone
{
public:
    HomePhone(const Person& p)
        : HomePhone(p, p.get_position())
    {}

    HomePhone(const Person& p, int position)
        : Phone(p),
        _position { position }
    {}

    void ring() const
    {
        if(_position == _owner.get_position())
        {
            _owner.answer_phone();
        }
        else
        {
            _owner.nos_answer_phone();
        }
    }

private:
    int _position;
};