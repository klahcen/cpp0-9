#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat;
        bureaucrat.increment_Grade(); 
    }
    catch (std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
}