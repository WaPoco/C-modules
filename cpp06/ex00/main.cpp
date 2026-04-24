#include "ScalarConverter.hpp"
#include "exception"
#include "iostream"
#include <cstdlib>
#include <cerrno>

int main(int arg, char **args)
{
    std::string s = args[1];
    ScalarConverter::convert(s);
    return (1);
}