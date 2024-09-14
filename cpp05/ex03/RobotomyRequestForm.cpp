#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : name(), is_signed(false), grade_to_signed(72), graed_to_execute(45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(std::string name, int grade_s, int grade_e, std::string target)
    : name(name), is_signed(false), grade_to_signed(grade_s), graed_to_execute(grade_e), target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : name(other.name), is_signed(other.is_signed), grade_to_signed(other.grade_to_signed), \
    graed_to_execute(other.graed_to_execute), target(other.target){}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm &other)
{
    if(this != &other)
    {
        this->is_signed = other.is_signed;
        this->target = other.target;
    }
    return *this;
}


RobotomyRequestForm::~RobotomyRequestForm(){

}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    this->check_re(executor);
    srand(time(0));
    if(rand()%2)
        std::cout<<"informs that "<<this->target<<" has been robotomized successfully."<<std::endl;
    else
        std::cout<<" informs that the robotomy failed."<<std::endl;
}