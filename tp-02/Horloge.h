#pragma once

#include <vector>

#include "Event.h"

class MinuteHand {
public:
    int get_minutes() const;
    void advance();                     
  
private:
    int _minutes = 0;                
};

class SecondHand {
public:
  SecondHand(MinuteHand&);
  SecondHand& operator=(const SecondHand&); 
  
  int get_seconds() const;     
  void advance();                
  
private:
  int _seconds;
  MinuteHand& _min_hand;
};

class Clock
{
public:
    Clock(MinuteHand&);

    void tick();
    void add_event(const Event&);

private:
    MinuteHand& _min_hand;
    SecondHand _sec_hand;
    std::vector<Event> _events;
};