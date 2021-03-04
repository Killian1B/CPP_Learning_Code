#pragma once

#include "Pokemon.h"

#include <vector>

class PokeCenter
{
public:
    void heal(const std::vector<std::reference_wrapper<Pokemon>>& pokemons)
    {
        // Remplace auto* par Pokemon& plutôt que auto& pour ne pas avoir à faire le get() en dessous.
        for (Pokemon& pokemon : pokemons)
        {
            if (pokemon.get_level() == 0)
            {
                _traumatized_pokemons.emplace_back(pokemon);
            }
        }
    }

    std::vector<std::reference_wrapper<Pokemon>> get_traumatized()
    {
        auto tmp = _traumatized_pokemons;
        _traumatized_pokemons.clear();
        return tmp;
    }

private:
    std::vector<std::reference_wrapper<Pokemon>> _traumatized_pokemons;
};
