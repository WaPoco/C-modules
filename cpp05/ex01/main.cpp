#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "\n=== TEST 1: Valid Form Creation ===\n";
    try
    {
        Form contract("Contract", 50, 25);
        std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Form Grade Too High ===\n";
    try
    {
        Form invalid("InvalidHigh", 0, 25);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Form Grade Too Low ===\n";
    try
    {
        Form invalid("InvalidLow", 50, 151);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Successful Signing ===\n";
    try
    {
        Bureaucrat boss("Boss", 1);
        std::cout << boss << std::endl;

        Form permit("Permit", 10, 5);

        boss.signForm(permit);
        std::cout << permit << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Failed Signing ===\n";
    try
    {
        Bureaucrat intern("Intern", 100);
        std::cout << intern << std::endl;
        Form permit("Permit", 50, 25);

        intern.signForm(permit);
        std::cout << permit << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 6: Boundary Grades ===\n";
    try
    {
        Form top("TopSecret", 1, 1);
        Form bottom("Paperwork", 150, 150);

        std::cout << top << std::endl;
        std::cout << bottom << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 7: Exact Required Grade ===\n";
    try
    {
        Bureaucrat worker("Worker", 42);
        Form report("Report", 42, 42);

        worker.signForm(report);
        std::cout << report << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}