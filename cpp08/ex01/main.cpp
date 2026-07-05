#include"Span.hpp"

int main()
{
    Span sp = Span(3);
    sp.addNummber(12);
    sp.addNummber(1);
    sp.addNummber(23);
    std::cout << "longest span " << sp.longstSpan() << std::endl;
    std::cout << "shortest span " << sp.shortestSpan() << std::endl;
    return (1);
}