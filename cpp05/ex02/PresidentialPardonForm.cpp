#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm()
    : AForm(), target(){}

PresidentialPardonForm::PresidentialPardonForm (std::string target)
    : AForm("PresidentialPardonForm", 25, 5), target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm  &other)
    : AForm(other), target(other.target){}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm &other)
{
    if(this != &other)
        this->target = other.target;
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm(){

}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
    this->check_re(executor);
    std::cout<<this->target<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
}