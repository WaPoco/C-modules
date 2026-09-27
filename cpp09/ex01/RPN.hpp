#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
private:
    std::stack<int> _stack;

    bool isOperator(char c) const;
    void applyOperator(char op);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    void calculate(const std::string& expression);
};

#endif
