#include "Base.hpp"
#include "A.hpp"
#include "B.cpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base(){

}

Base * generate(void){
    srand(time(0));
    int i =rand()%3;
    if(rand()%3)
    {
        if(i == 0)
            return new(A);
        else if ( i == 1)
            return new(B);
        else
            return new(C);
    }
    return NULL;
}

void identify(Base* p){
    if(dynamic_cast<A*>(p))
        std::cout<<"A"<<std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout<<"B"<<std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout<<"C"<<std::endl;
    else
        std::cout<<"Error type"<<std::endl;
}

void identify(Base& p){
    try{
        A& a = dynamic_cast<A&>(p);
        std::cout<<"A"<<std::endl;
        return ;
    }
    catch(std::bad_cast&){}
    try{
        B& b = dynamic_cast<B&>(p);
        std::cout<<"B"<<std::endl;
        return ;
    }
    catch(std::bad_cast&){}
    try{
        C& c = dynamic_cast<C&>(p);
        std::cout<<"C"<<std::endl;
        return;
    }
    catch(std::bad_cast&){}
    std::cout<<"Error type"<<std::endl;
}
