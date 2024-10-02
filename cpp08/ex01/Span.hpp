#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span{
    private:
        int N;
        int nbr_stored;
        std::vector<int> array;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
};

#endif