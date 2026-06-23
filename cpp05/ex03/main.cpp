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
    {
        Intern intern;

        AForm* form1 = intern.makeForm("robotomy request", "Bender");
        AForm* form2 = intern.makeForm("shrubbery creation", "home");
        AForm* form3 = intern.makeForm("presidential pardon", "Arthur Dent");
        AForm* form4 = intern.makeForm("coffee request", "nobody");

        delete form1;
        delete form2;
        delete form3;
        delete form4;
    }
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);

        AForm* forms[3];

        forms[0] = intern.makeForm("shrubbery creation", "garden");
        forms[1] = intern.makeForm("robotomy request", "Bender");
        forms[2] = intern.makeForm("presidential pardon", "Ford");

        for (int i = 0; i < 3; i++)
        {
            if (forms[i])
            {
                boss.signForm(*forms[i]);
                boss.executeForm(*forms[i]);
            }
        }

        for (int i = 0; i < 3; i++)
            delete forms[i];
    }
    {
        Intern intern;

        AForm* form = intern.makeForm("tax evasion form", "Bob");

        if (!form)
            std::cout << "NULL returned correctly" << std::endl;

        delete form;
    }
    return (0);
}
