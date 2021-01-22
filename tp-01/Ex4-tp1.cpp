#include <iostream>
#include <vector>

std::vector<unsigned int> count_lower(const std::string& chaine)
{
    std::vector<unsigned int> tab(26, 0);
    for(auto lettre : chaine)
    {
        if(lettre >= 'a' and lettre <= 'z')
        {
            tab.at(lettre - 'a')++;
        }
    }
    return tab;
}

void display_lower_occ(const std::vector<unsigned int>& tab)
{
    for(size_t i = 0; i < tab.size(); i++)
    {
        std::cout << char('a' + i) << " : " << tab.at(i) << std::endl;
    }
}

int main()
{
    std::string chaine;
    std::string mot;

    do
    {
        std::cin >> mot;
        chaine += mot;
    } while (mot != "\"\"" and mot != "\'\'");
    
    auto tab = count_lower(chaine);
    display_lower_occ(tab);

    return 0;
}