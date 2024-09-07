#include "Bureaucrat.hpp"

std::string Bureaucrat::getName(){
    return this->name;
}
int Bureaucrat::getGrade(){
    return this->grade;
}
void Bureaucrat::increment_Grade(){
    this->grade--;
    if(this->grade<1)
        throw "GradeTooHighException";
}
void Bureaucrat::decrement_Grade(){
    this->grade++;
    if(this->grade>150)
        throw "GradeTooLowException";
}