#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat b("Adolf", 100);
        b.signForm();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}