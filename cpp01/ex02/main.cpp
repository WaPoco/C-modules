#include <string>
#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR;
    stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "The memory address of a string " << &str << std::endl;
    std::cout << "The memory address of a pointer to a string " << stringPTR << std::endl;
    std::cout << "The memory address of a reference to a string " <<  &stringREF << std::endl;

    std::cout << "The value of a string " << str << std::endl;
    std::cout << "The value of a pointer to a string " << *stringPTR << std::endl;
    std::cout << "The value of a reference to a string " << stringREF << std::endl;
    return (0);
}