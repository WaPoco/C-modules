#include"Span.hpp"

int main()
{
    Span sp = Span(5);
    std::vector<int> v = {1,1,30,4,5,5,6};
    /*sp.addNumber(1);
    sp.addNumber(1);
    sp.addNumber(3);
    sp.addNumber(4);
    sp.addNumber(5);*/
    sp.addMultipleNumbers(v);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return (1);
}