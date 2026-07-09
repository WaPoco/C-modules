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
        void addMultipleNumbers(std::vector<int> numbers);
};