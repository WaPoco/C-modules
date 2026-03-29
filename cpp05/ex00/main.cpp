#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    //Test 1: Create a Bureaucrat with a valid grade
    std::cout << "Test 1: Create a Bureaucrat with a valid grade\n";
    try
    {
        Bureaucrat a("Vasili", 3);
        std::cout << a;
        a.decrementGrade();
        std::cout << a;
        a.incrementGrade();
        std::cout << a;
    }
        catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    //Test 2: Create a Bureaucrat with an invalid grade (too low)
    std::cout << "\nTest 2: Create a Bureaucrat with an invalid grade (too low)\n";
    try
    {
        Bureaucrat b("John", 151);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    //Test 3: Create a Bureaucrat with an invalid grade (too high)
    std::cout << "\nTest 3: Create a Bureaucrat with an invalid grade (too high)\n";
    try
    {
        Bureaucrat c("Jane", 0);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    //Test 4: Incrementing a grade that is already at the maximum
    std::cout << "\nTest 4: Incrementing a grade that is already at the maximum\n";
    try
    {
        Bureaucrat d("Alice", 0);
        d.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}