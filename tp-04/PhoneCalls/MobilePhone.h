#pragma once

#include "Phone.h"

class MobilePhone: public Phone
{
public:
    MobilePhone(const Person& p)
        : MobilePhone(p, p.get_position())
    {}

    MobilePhone(const Person& p, int position)
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
