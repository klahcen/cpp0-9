#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try{
        Bureaucrat bureaucrat(1,"b");
        ShrubberyCreationForm sform("target");
        RobotomyRequestForm  rform("gf");
        PresidentialPardonForm pform("p");
        Intern      s;
        AForm    *b;
        b = s.makeForm("presidential pardon", "e");
        b->beSigned(bureaucrat);
        b->execute(bureaucrat);
    // sform.execute(bureaucrat);
    //     Bureaucrat bureaucrat("bureaucrat", 1);
    //     Form    form("form", 1, 99);
    //     Form    form1;
    //     // bureaucrat.signForm(form1);
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