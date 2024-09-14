#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat bureaucrat(2,"bureaucrat");
        Form    form("form", 1, 99);
        // Form    form1;
        bureaucrat.signForm(form);
        bureaucrat.signForm(form);
        // form1 = form; 
        // bureaucrat.signForm(form);
        // bureaucrat.decrement_Grade();
        // bureaucrat.signForm(form);
        // bureaucrat.signForm(form);
        // bureaucrat.signForm(form);
        std::cout<<form;
        std::cout<<"********************************************"<<std::endl;
        std::cout<<bureaucrat;
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }

}