#include "Span.hpp"


Span::Span():N(0), nbr_stored(0), array(0){
}

Span::Span(unsigned int N){
    nbr_stored = 0;
    this->N = N;
    if(array.size())
        array.clear();
    this->array.resize(N,1);
}

Span::Span(const Span& other){
    *this = other;
}

Span& Span::operator=(const Span& other){
    if(this != &other)
    {

    }
    return *this;
}

Span::~Span(){
}

void Span::addNumber(int n){
    if(this->N > this->nbr_stored)
    {
        this->array.at(nbr_stored)=n;
        this->nbr_stored++;
    }
    else
        throw std::runtime_error("Error");
}

int Span::shortestSpan(){
    int shor=0;
    for(size_t i=0; i<array.size();i++){
        if(i+1<array.size() && shor>= array[i]-array[i+1])
            shor = array[i] - array[i+1];
    }

    return shor;
}

int Span::longestSpan(){
    return 0;
}