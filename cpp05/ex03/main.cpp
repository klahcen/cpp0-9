#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat bureaucrat("b", 10);
    // ShrubberyCreationForm sform("f", 20,20,"target");
    // rform.beSigned(bureaucrat);
    // RobotomyRequestForm  rform("targ");
    Intern intern;
    AForm *form;
    try{
        form = intern.makeForm("", "rae");
        form->execute(bureaucrat);
        // std::cout<<form<<std::endl;
    // sform.execute(bureaucrat);
    // rform.execute(bureaucrat);
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