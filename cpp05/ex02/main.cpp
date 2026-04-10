#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat b("Adolf", 60);
        std::cout << b;
        AForm f("B12", 70, 120);
        ShrubberyCreationForm d("Home");
        d.beSigned(b);
        d.execute(b);
        b.signForm(f);
        b.executeForm(f);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}