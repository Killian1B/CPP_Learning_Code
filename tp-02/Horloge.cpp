#include "Horloge.h"

// MinuteHand
int MinuteHand::get_minutes() const
{
    return _minutes;
}

void MinuteHand::advance()
{
    _minutes++;
}


// SecondHand
SecondHand::SecondHand(MinuteHand& minute) : 
    _seconds { 0 },
    _min_hand { minute }
{}

int SecondHand::get_seconds() const
{
    return _seconds;
}

void SecondHand::advance()
{
    if(++_seconds == 60)
    {
        _seconds = 0;
        _min_hand.advance();
    }
}

SecondHand& SecondHand::operator=(const SecondHand& other)
{
    if(this != &other)
    {
        _min_hand = other._min_hand;
        _seconds = other._seconds;
    }
    return *this;
}


// Clock
Clock::Clock(MinuteHand& minute): 
    _min_hand { minute },
    _sec_hand { SecondHand(minute) }
{}

void Clock::tick()
{
   _sec_hand.advance();
   for(auto i = _events.begin(); i != _events.end();)
   {
       if((*i).notify_time(_min_hand.get_minutes(), _sec_hand.get_seconds()))
       {
           _events.erase(i);
       }
       else 
       {
           i++;
       }
   }
}

void Clock::add_event(const Event& event)
{
    _events.emplace_back(event);
}