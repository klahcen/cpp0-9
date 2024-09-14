#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat(15, "maohhmed");
        bureaucrat.decrement_Grade();
        bureaucrat.increment_Grade();
        bureaucrat.increment_Grade();
       std::cout << bureaucrat ;
    }
    catch (std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
}