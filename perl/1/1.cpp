#include <set>
#include <iostream>

int main()
{
    std::set<int> s;
    int i;
    while (std::cin >> i)
    {
        s.insert(i);
    }
    std::cout << "------" << std::endl;
    for (auto j = s.begin(); j != s.end(); ++j)
    {
        std::cout << *j << std::endl;
    }
    return 0;
}