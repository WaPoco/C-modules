#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

static void printTestTitle(const std::string &title)
{
    std::cout << "\n=== " << title << " ===\n";
}

int main()
{
    srand(time(NULL));
    printTestTitle("TEST 1: Bureaucrat Grade Bounds");
    try
    {
        Bureaucrat tooHigh("TooHigh", 0);
        std::cout << tooHigh;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat tooLow("TooLow", 151);
        std::cout << tooLow;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printTestTitle("TEST 2: Form Grade Bounds");
    try
    {
        AForm tooHigh("TooHighForm", 0, 10);
        std::cout << tooHigh;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        AForm tooLow("TooLowForm", 10, 151);
        std::cout << tooLow;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printTestTitle("TEST 3: Signing Failure");
    try
    {
        Bureaucrat intern("Intern", 150);
        ShrubberyCreationForm form("Home");

        std::cout << intern;
        intern.signForm(form);
        std::cout << form;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printTestTitle("TEST 4: Successful Shrubbery Form");
    try
    {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm form("Home");

        std::cout << boss;
        boss.signForm(form);
        boss.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printTestTitle("TEST 5: Successful Robotomy Form");
    try
    {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm form("Bender");

        std::cout << boss;
        boss.signForm(form);
        boss.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printTestTitle("TEST 6: Successful Presidential Pardon Form");
    try
    {
        Bureaucrat boss("Boss", 1);
        PresidentialPardonForm form("Arthur Dent");

        std::cout << boss;
        boss.signForm(form);
        boss.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printTestTitle("TEST 7: Execution Without Signature");
    try
    {
        Bureaucrat boss("Boss", 1);
        PresidentialPardonForm form("Ford Prefect");

        boss.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    printTestTitle("TEST 8: Test");
    try
    {
        Bureaucrat test("test", 50);
        ShrubberyCreationForm form("test");
        test.signForm(form);

        test.executeForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}