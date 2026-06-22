#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>



int main()
{
    Intern  someRandomIntern; 
    AForm*  rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    return (0);
}