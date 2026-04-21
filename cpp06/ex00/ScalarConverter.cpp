#include "ScalarConverter.hpp"
#include <string>
#include <iostream>


ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string str)
{
    ScalarConverter::isInt(str);
    ScalarConverter::isChar(str);
    ScalarConverter::isDouble(str);
    ScalarConverter::isFloat(str);
}

bool ScalarConverter::isInt(std::string& s)
{
    if (!std::isdigit(s[0]) && s[0] != '-' && s[0] != '+')
        return false;
    for (size_t i = 1; i < s.length(); i++)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

void ScalarConverter::isChar(std::string& s)
{
    if(s.length() == 1 && !std::isdigit(s[0]))
        std::cout << "char: '" << s[0] << "'" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
}

void ScalarConverter::isDouble(std::string& s)
{
    char *end;
    errno = 0;
    double value = strtod(s.c_str(), &end);

    if (end == s.c_str())
    {
    // no numeric conversion happened
        std::cout << "double: impossible" << std::endl;
    }
    else if (errno == ERANGE)
    {
    // overflow or underflow
        std::cout << "double: out of range" << std::endl;
    }
    else if (*end != '\0')
    {
    // extra non-numeric characters remain
        std::cout << "double: impossible" << std::endl;
    }
    else
    {
        std::cout << "double: " << value << std::endl;
    }
}

void ScalarConverter::isFloat(std::string &s)
{
    char *end;
    errno = 0;
    float value = strtof(s.c_str(), &end);

    if (end == s.c_str())
    {
    // no numeric conversion happened
        std::cout << "float: impossible" << std::endl;
    }
    else if (errno == ERANGE)
    {
    // overflow or underflow
        std::cout << "float: out of range" << std::endl;
    }
    else if (*end != '\0')
    {
    // extra non-numeric characters remain
        std::cout << "float: impossible" << std::endl;
    }
    else
    {
        std::cout << "float: " << value << "f" << std::endl;
    }
}
