#include <algorithm>
#include <iostream>
#include <exception>
#include <vector>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> span;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        ~Span();
        Span& operator=(const Span &other);
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
        template<typename Iterator>
        void addMultipleNumbers(Iterator start, Iterator end);
};

template<typename Iterator>
void Span::addMultipleNumbers(Iterator begin, Iterator end)
{
    int distance;

    distance = std::distance(begin, end);
    if (span.size() + distance <= _N)
    {
        span.insert(span.end(), begin, end);
        return ;
    }
}