#include <algorithm>
#include <iostream>
#include <exception>
#include <stdexcept>
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
    typename std::iterator_traits<Iterator>::difference_type distance;

    distance = std::distance(begin, end);
    if (distance < 0 || static_cast<std::vector<int>::size_type>(distance) > _N - span.size())
        throw std::out_of_range("Span is full");
    span.insert(span.end(), begin, end);
}