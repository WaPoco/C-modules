#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try 
    {
        Bureaucrat a("Vasili", -1);
        std::cout << a << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    return (0);
}