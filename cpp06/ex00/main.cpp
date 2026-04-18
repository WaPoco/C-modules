#include "ScalarConverter.hpp"
#include "exception"
#include "iostream"
#include <cstdlib>
#include <cerrno>

int main(int arg, char **args)
{
    std::string s = args[1];
    char* end;


    float i = std::strtof(s.c_str(), &end);
    double d = std::strtod(s.c_str(), &end);

    std::cout << i << ", " << d << std::endl;
    errno = 0;
    float val = std::strtof(s.c_str(), &end);

    if (end == s) {
        std::cout << "No conversion\n";
    } else if (errno == ERANGE) {
        std::cout << "Out of range\n";
    } else {
        std::cout << "Value: " << val << "\n";
    }
}