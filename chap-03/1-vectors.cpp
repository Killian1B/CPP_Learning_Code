#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    //std::vector<int> values { 4, 0 };
    std::vector<int> values(4, 0);
    int array[] = { 0, 1, 2, 3, 4, 5 };

    for (const auto v: values)
    {
        std::cout << v << std::endl;
    }
    return 0;

    std::vector<int> part(&array[2], &array[5]);
    for (const auto v: part)
    {
        std::cout << v << std::endl;
    }

    std::vector<int> full(array, array + 6);
    for (const auto v: part)
    {
        std::cout << v << std::endl;
    }

    for (size_t left = 0, right = full.size() - 1; left < right; ++left, --right)
    {
        std::swap(full[left], full[right]);
    }

    for (auto it = full.begin(); it != full.end(); it += 2)
    {
        it = full.insert(it, *it);
    }

    while (!full.empty())
    {
        full.pop_back();
    }

    full.erase(full.begin() + 3);

    full.erase(full.begin() + 2, full.begin() + 7);

    const auto it = std::find(full.begin(), full.end(), 5);
    if (it != full.end())
    {
        full.erase(it);
    }

    std::vector<int> v;
    v.assign(5, 2);
    v.assign({ 0, 2, 32, -4, 3 });
    v.clear();
}