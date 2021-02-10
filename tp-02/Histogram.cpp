#include "Histogram.h"

Histogram::Histogram()
    : _count { new unsigned int[26] }
{}

Histogram::Histogram(const Histogram& other)
    : _count { other._count }
{}

Histogram::~Histogram()
{
    delete[] _count;
}

Histogram& Histogram::operator=(const Histogram& other)
{
    if(this != &other)
    {
        _count = other._count;
    }
    return *this;
}


void Histogram::analyze(const std::string& chaine)
{
    for(auto lettre : chaine)
    {
        if(lettre >= 'a' and lettre <= 'z')
        {
            _count[lettre - 'a']++;
        }
    }
}

void Histogram::print() const
{
    for(size_t i = 0; i < 26; i++)
    {
        std::cout << char('a' + i) << " : " << _count[i] << std::endl;
    }
}

int main()
{
    Histogram histo{};
    std::string chaine;
    std::string mot;

    do
    {
        std::cin >> mot;
        chaine += mot;
    } while (mot != "\"\"" and mot != "''");

    histo.analyze(chaine);
    histo.print();

    Histogram h1,h2;
    Histogram h3{Histogram{h1}};

    return 0;
}