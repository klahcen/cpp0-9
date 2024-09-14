#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat bureaucrat("bureaucrat", 1);
        Form    form("form", 1, 99);
        Form    form1;
        // bureaucrat.signForm(form1);
        form1 = form; 
        // bureaucrat.signForm(form);
        // bureaucrat.decrement_Grade();
        // bureaucrat.signForm(form);
        // bureaucrat.signForm(form);
        // bureaucrat.signForm(form);
        std::cout<<form;
        std::cout<<"********************************************"<<std::endl;
        std::cout<<form1;
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }

}