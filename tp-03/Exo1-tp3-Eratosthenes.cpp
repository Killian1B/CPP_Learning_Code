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
    std::unordered_set<unsigned long> us;
    unsigned long size = 35;

    for(unsigned long i = 2; i <= size; i++)
    {
        v.emplace_back(i);
        dq.push_back(i);
        s.emplace(i);
        us.insert(us.end(), i);
    }

    for(auto i = v.begin(); i != v.end(); ++i)
    {
        for(auto j = i+1; j != v.end();)
        {
            if((*j % *i) == 0)
                j = v.erase(j);
            else
                j++;
        }
    }
    std::cout << "Il y a " << v.size() << " éléments restants. (vector)" << std::endl;

    for(auto i = 0; (dq.begin()+i) != dq.end(); ++i)
    {
        for(auto j = i+1; (dq.begin()+j) != dq.end();)
        {
            if((*(dq.begin()+j) % *(dq.begin()+i)) == 0)
                dq.erase(dq.begin()+j);
            else
                ++j;
        }
    }
    std::cout << "Il y a " << dq.size() << " éléments restants. (deque)" << std::endl;
    
    int n = 1;
    for(auto i = s.begin(); i != s.end(); ++i)
    {
        for(auto j = (*i)+1; j <= *(s.end()) + n; ++j)
        {
            if((j % *i) == 0 )
            {
                n += s.erase(j);
            }
        }
    }
    std::cout << "Il y a " << s.size() << " éléments restants. (set)" << std::endl;

   /* //int m = 1;
    for(auto i = us.begin(); i != us.end(); ++i)
    {
        std::cout << "i = " << *i << std::endl;
        for(auto j = (*i)+1; j <= *(us.end()) + m; ++j)
        {
            if((j % *i) == 0 )
            {
                m += us.erase(j);
            }
        }
    }
    std::cout << "Il y a " << us.size() << " éléments restants. (unordered_set)" << std::endl;
    */
}
