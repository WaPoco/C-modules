#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(3);
    v.push_back(7);
    v.push_back(100);
    try
    {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Found: " << *it << std::endl;   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        easyfind(v, 100);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    try
    {
        std::list<int>::iterator it = easyfind(l, 2);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}