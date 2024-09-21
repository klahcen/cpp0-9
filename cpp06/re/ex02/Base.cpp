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
    int i = rand()%3;
    if(i == 0)
        return new(A);
    else if ( i == 1)
        return new(B);
    return new(C);
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
    A a;
    B b;
    C c;
    try{
        a = dynamic_cast<A&>(p);
        std::cout<<"A"<<std::endl;
        return ;
    }
    catch(std::bad_cast&){}
    try{
        b = dynamic_cast<B&>(p);
        std::cout<<"B"<<std::endl;
        return ;
    }
    catch(std::bad_cast&){}
    try{
        c = dynamic_cast<C&>(p);
        std::cout<<"C"<<std::endl;
    }
    catch(std::bad_cast&)
    {
        std::cout<<"Error type"<<std::endl;
    }
    
}
