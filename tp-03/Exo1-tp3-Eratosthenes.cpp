#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <unordered_set>

int main()
{
    std::vector<unsigned long> v;
    std::deque<unsigned long> dq;
    std::set<unsigned long> s;

    for(unsigned long i = 2; i <= 100000; i++)
    {
        v.emplace_back(i);
        dq.push_back(i);
        s.emplace(i);
    }

    for(auto i = v.begin(); i != v.end(); ++i)
        for(auto j = i+1; j != v.end();)
        {
            if((*j % *i) == 0)
                j = v.erase(j);
            else
                j++;
        }
    std::cout << "Il y a " << v.size() << " éléments restants. (vector)" << std::endl;
    
    for(auto i = dq.begin(); i != dq.end(); ++i)
        for(auto j = i+1; j != dq.end(); ++j)
        {
            if((*j % *i) == 0)
            {
                dq.erase(j);
                j--;
            }
        }
    std::cout << "Il y a " << dq.size() << " éléments restants. (deque)" << std::endl;
    
    for(auto i = s.begin(); i != s.end(); ++i)
        for(auto j = *i+1; j != *s.end();)
        {
            if((j % *i) == 0 and j != *i)
                s.erase(j);
            else
                ++j;
        }
    std::cout << "Il y a " << s.size() << " éléments restants. (set)" << std::endl;
    
}
