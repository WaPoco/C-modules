#include "RNP.hpp"

void    read_input(std::string &input, std::stack<int> &numbers, std::stack<char> &operation)
{

    for (int i = 0; i < input.length(); i++)
    {
        if ('0' <= input[i] && input[i] <= '9')
            numbers.push(input[i] - '0');
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
            operation.push(input[i]);
    }
}