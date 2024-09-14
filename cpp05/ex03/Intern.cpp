#include "Intern.hpp"

Intern::Intern(){

}

Intern::Intern(const Intern &other){
    *this = other;
}

Intern& Intern::operator= (const Intern &other){
    if(this!=&other)
        *this = other;
    return *this; 
}

Intern::~Intern(){

}

AForm* Intern::makeForm(std::string name, std::string target){
    AForm *form=NULL;
    int n=0;
    std::string strings[4]={"presidential pardon","robotomy request","shrubbery creation"};
    for(int i=0; i < 3; i++)
    {
        if(strings[i] == name){
            n = i + 1;
            break;
        }
    }
    switch(n)
    {
        case 1:
        {
            form  = new PresidentialPardonForm(target);
            std::cout<<"Intern creates PresidentialPardonForm"<<std::endl;
            break;
        }
        case 2:
        {
            form = new RobotomyRequestForm(target);
            std::cout<<"Intern creates RobotomyRequestForm"<<std::endl;
            break;
        }
        case 3:
        {
            form = new ShrubberyCreationForm(target);
            std::cout<<"Intern creates SHRUBBERYCREATIONFORM"<<std::endl;
            break;
        }
        default:
            throw AForm::Error();
    }
    return form;
}