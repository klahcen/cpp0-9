#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target)
     : name(), is_signed(false), grade_to_signed(25), graed_to_execute(5), target(target){}

PresidentialPardonForm::PresidentialPardonForm (std::string name, int grade_s, int grade_e, std::string target)
    : name(name), is_signed(false), grade_to_signed(grade_s), graed_to_execute(grade_e), target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm  &other)
    : name(other.name), is_signed(other.is_signed), grade_to_signed(other.grade_to_signed), \
    graed_to_execute(other.graed_to_execute), target(other.target){}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm &other){
    if(this != &other)
    {
        this->is_signed = other.is_signed;
        this->target = other.target;
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm(){

}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
    this->check_re(executor);
    std::cout<<this->target<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
}