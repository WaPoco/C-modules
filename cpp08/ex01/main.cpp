#include"Span.hpp"


int main()
{
    {
        Span sp = Span(100);
        //std::vector<int> v;
        //v = {1, 1, 30, 4, 55, 56};
        sp.addNumber(1);
        sp.addNumber(1);
        sp.addNumber(3);
        sp.addNumber(4);
        sp.addNumber(5);
        //sp.addMultipleNumbers(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    return (1);
}