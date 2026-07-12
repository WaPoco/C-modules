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

void Span::addNumber(int number)
{
    if (span.size() - 1 == _N)
        throw std::out_of_range("Span is full");
    span.push_back(number);    
}

int Span::shortestSpan()
{
    int shortest;

    if (span.size() <= 1)
        throw std::out_of_range("Size smaller than 1");
    
    std::vector<int> sort_span = span;
    std::sort(sort_span.begin(), sort_span.end());
    shortest = sort_span[1] - sort_span[0];
    for (int i = 1; i < sort_span.size() - 1; i++)
    {
        if (sort_span[i + 1] - sort_span[i] < shortest)
            shortest = sort_span[i + 1] - sort_span[i];
    }
    return (shortest);
}

int Span::longestSpan()
{
    if (span.size() <= 1)
        throw std::out_of_range("Size smaller than 1");
    std::vector<int> sort_span = span;    
    std::sort(sort_span.begin(), sort_span.end());
    int longest = -sort_span.front() + sort_span.back();
    return longest;
}
