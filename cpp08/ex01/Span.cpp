#include "Span.hpp"

Span::Span():_N(0)
{
}

Span::Span(unsigned int N):_N(N)
{
}

Span::Span(const Span &other)
{

}

Span::~Span()
{

}

Span &Span::operator=(const Span &other)
{
    return *this;
}

void Span::addNummber(int number)
{
    if (span.size() - 1 == _N)
        throw std::out_of_range("Span is full");
    span.push_back(number);    
}

int Span::shortestSpan()
{
    std::vector<int> sort_span = span;    
    std::sort(sort_span.begin(), sort_span.end());
    int shortest = ++sort_span.front() - sort_span.front();
    return (shortest);
}

int Span::longstSpan()
{
    std::vector<int> sort_span = span;    
    std::sort(sort_span.begin(), sort_span.end());
    int longest = -sort_span.front() + sort_span.back();
    return longest;
}
