#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm(), target(){}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target){}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm &other)
{
    if(this != &other)
    {
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
        std::cout<<this->target<<" has been robotomized successfully."<<std::endl;
    else
        std::cout<<"the robotomy failed."<<std::endl;
}