#pragma once

#include <iostream>
#include <vector>

#include "Animal.h"
#include "Cow.h"
#include "Dog.h"
#include "Chicken.h"
#include "Cat.h"

class Opera
{
public:
    Opera()
    {
        _animals.emplace_back(new Cat {});
        _animals.emplace_back(new Chicken {});
        _animals.emplace_back(new Cow {});
        _animals.emplace_back(new Dog {});
    }

    ~Opera()
    {
        for (auto* animal: _animals)
        {
            delete animal;
        }
    }

    void sing() const
    {
        for (const auto* animal: _animals)
        {
            animal->sing(' ');
        }

        std::cout << std::endl;
    }

private:
    std::vector<Animal*> _animals;
};