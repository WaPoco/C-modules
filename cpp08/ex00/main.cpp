#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values = {1, 2, 3, 4, 5};
    std::cout << *easyfind(values, 1) << std::endl;
    return (0);
}