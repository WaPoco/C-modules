#include <algorithm>
#include <iostream>
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
        void addNummber(int number);
        int shortestSpan();
        int longstSpan();
};