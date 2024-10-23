#include "Span.hpp"
#include <cmath>
#include <climits>

Span::Span() : N(0), nbr_stored(0), array(0)
{
}

Span::Span(unsigned int N)
{
    nbr_stored = 0;
    this->N = N;
    if (array.size())
        array.clear();
    this->array.resize(N, 1);
}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->nbr_stored = other.nbr_stored;
        this->array = other.array;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (this->N > this->nbr_stored)
    {
        this->array.at(nbr_stored) = n;
        this->nbr_stored++;
    }
    else
        throw std::runtime_error("Error");
}

int Span::shortestSpan()
{
    int shor = INT_MAX;
    int max = 0;
    int min = 0;
    for (size_t i = 0; i < array.size(); i++)
    {

        for (size_t j = i + 1; j < array.size(); j++)
        {
            if (i < array.size())
            {
                max = std::max(array[i], array[j]);
                min = std::min(array[i], array[j]);
                if (shor > (max - min))
                    shor = (max - min);
            }
        }
    }
    return shor;
}
int Span::longestSpan()
{
    int log = 0;
    int max = 0;
    int min = 0;
    for (size_t i = 0; i < array.size(); i++)
    {
        for (size_t j = i + 1; j < array.size(); j++)
        {
            if (i < array.size())
            {
                max = std::max(array[i], array[j]);
                min = std::min(array[i], array[j]);
                if (log < (max - min))
                    log = (max - min);
            }
        }
    }

    return log;
}