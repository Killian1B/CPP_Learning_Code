#pragma once

#include "Texture.h"

#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>

class Texture
{
public:
    class Cache
    {
    public:
        std::shared_ptr<Texture> Load(const std::string& name)
        {
            auto it = _textures.find(name);
            if (it != _textures.end())
            {
                if (auto texture = it->second.lock())
                {
                    return texture;
                }

                // Il ne faut pas oublier de supprimer l'ancien élément, car
                // les fonctions d'insertion d'unordered_map ne font rien lorsqu'une
                // valeur est déjà présente.  
                _textures.erase(it);
            }
            std::cout << "Texture width: ";
            std::cout.flush();

            int width = 0;
            std::cin >> width;

            std::cout << "Texture height: ";
            std::cout.flush();

            int height = 0;
            std::cin >> height;

            // On remplace make_shared par un new.
            std::shared_ptr<Texture> texture { new Texture { name, width, height } };
            _textures.emplace_hint(it, name, std::weak_ptr { texture });
            return texture;
        }

    private:
        std::unordered_map<std::string, std::weak_ptr<Texture>> _textures;
    };

    static std::shared_ptr<Texture> Load(Cache& cache, const std::string& name)
    {
        return cache.Load(name);
    }

    static unsigned int Count() { return _count; }

    Texture(std::string_view name, int width, int height)
        : _name { name }
        , _width { width }
        , _height { height }
    {
        std::cout << *this << " has been loaded." << std::endl;
        ++_count;
    }

    ~Texture()
    {
        --_count;
        std::cout << *this << " has been unloaded." << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Texture& texture)
    {
        return stream << "Texture " << texture._name << " (" << texture._width << "x" << texture._height << ")";
    }

    const std::string& get_name() const { return _name; }

private:
    static inline unsigned int _count = 0u;

    std::string _name;
    int _width;
    int _height;
};
