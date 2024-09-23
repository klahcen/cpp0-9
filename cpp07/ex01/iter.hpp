#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void f(T arry[], size_t len){
    for(size_t i=0; i < len; i++)
        std::cout<<arry[i]<<std::endl;
}

template<typename T>
void iter(T arry[], size_t len, void (*f)(T[], size_t))
{
    if(len > 0)
        f(arry, len);
}

#endif