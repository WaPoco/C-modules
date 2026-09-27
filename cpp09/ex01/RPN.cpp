#include "RPN.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

RPN::RPN()
{
}

RPN::RPN(const RPN& other) : _stack(other._stack)
{
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN()
{
}

bool RPN::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::applyOperator(char op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error");

    int right = _stack.top();
    _stack.pop();

    int left = _stack.top();
    _stack.pop();

    int result = 0;

    switch (op)
    {
        case '+':
            result = left + right;
            break;
        case '-':
            result = left - right;
            break;
        case '*':
            result = left * right;
            break;
        case '/':
            if (right == 0)
                throw std::runtime_error("Error");
            result = left / right;
            break;
    }

    _stack.push(result);
}

void RPN::calculate(const std::string& expression)
{
    for (std::size_t i = 0; i < expression.length(); ++i)
    {
        char token = expression[i];

        if (token == ' ')
            continue;

        if (token >= '0' && token <= '9')
        {
            _stack.push(token - '0');
        }
        else if (isOperator(token))
        {
            applyOperator(token);
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    std::cout << _stack.top() << std::endl;
}
