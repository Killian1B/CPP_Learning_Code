#pragma once

#include <iostream>

#include "Animal.h"

class Chicken: public Animal
{
public:
    virtual ~Chicken() { std::cout << "CotCooooooooot!" << std::endl; }
    void sing(char next_char) const override { std::cout << "Cotcotcotcodet" << next_char; }
};
