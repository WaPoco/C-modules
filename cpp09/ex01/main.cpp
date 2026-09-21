#include "RNP.hpp"

int main(int argc, char **args)
{
    std::stack<int> numbers;
    std::stack<char> operation;
    int len;

    // create two stacks one with numbers and one with operations
    len = sizeof(args[1]) / sizeof(char);
    std::string str(args[1], len);
    read_input(str, numbers, operation);
    std::cout << "number 1: " << numbers.top() << std::endl;
    std::cout << operation.top() << std::endl;
    std::cout << "number 2: " << numbers.top() << std::endl;
    return 1;
}