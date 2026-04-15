#include "ScalarConverter.hpp"
#include "exception"
#include "iostream"

int main(int arg, char **args)
{
    //ScalarConverter a;
    int a = 1;
    try
    {
        double b = static_cast<double>(args[1]);

    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    return (1);
}