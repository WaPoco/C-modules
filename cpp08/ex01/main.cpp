#include"Span.hpp"

int main()
{
    {
        Span sp = Span(100);
        std::vector<int> v;
        v.push_back(1);
        v.push_back(1);
        v.push_back(30);
        v.push_back(4);
        v.push_back(55);
        v.push_back(56);
        sp.addNumber(1);
        sp.addNumber(1);
        sp.addNumber(3);
        sp.addNumber(4);
        sp.addNumber(5);
        sp.addMultipleNumbers(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    return (0);
}