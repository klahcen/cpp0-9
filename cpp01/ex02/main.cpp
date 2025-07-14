
#include <iostream>

int main()
{
    std::string str="HI THIS IS BRAIN";
    std::string *stringPTR;
    std::string &stringREF=str;
    stringPTR = &str;

    std::cout<<"print, The memory address"<<std::endl;
    std::cout<<"==>  of the string variable : "<<&str<<std::endl;
    std::cout<<"==>  held by                : "<<&stringPTR<<std::endl;
    std::cout<<"==>  held by                : "<<&stringREF<<std::endl;
    std::cout<<"print, The value"<<std::endl;
    std::cout<<"==>  of the string variable : "<<str<<std::endl;
    std::cout<<"==>  pointed to by          : "<<*stringPTR<<std::endl;
    std::cout<<"==>  pointed to by          : "<<stringREF<<std::endl;
    
}