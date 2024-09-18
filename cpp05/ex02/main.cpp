#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
    Bureaucrat bureaucrat(1,"b");
    ShrubberyCreationForm sform("target");
    RobotomyRequestForm  rform("gf");
    PresidentialPardonForm pform("p");
    pform.beSigned(bureaucrat);
    try{
    // sform.execute(bureaucrat);
    pform.execute(bureaucrat);
    //     Bureaucrat bureaucrat("bureaucrat", 1);
    //     Form    form("form", 1, 99);
    //     Form    form1;
        // bureaucrat.signForm(pform);
    //     form1 = form; 
    //     // bureaucrat.signForm(form);
    //     // bureaucrat.decrement_Grade();
    //     // bureaucrat.signForm(form);
    //     // bureaucrat.signForm(form);
    //     // bureaucrat.signForm(form);
    //     std::cout<<form;
    //     std::cout<<"********************************************"<<std::endl;
    //     std::cout<<form1;
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }

}