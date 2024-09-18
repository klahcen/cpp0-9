#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(),grade(-8){}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat &other){
    this->grade = other.grade;
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other){
    this->grade = other.grade;
}

Bureaucrat::~Bureaucrat(){

}

Bureaucrat::Bureaucrat(int grade, std::string name) : name(name), grade(grade){
    if(this->grade<1)
        throw GradeTooHighException();
    if(this->grade>150)
        throw GradeTooLowException();
}

std::string Bureaucrat::getName() const{
    return this->name;
}

int Bureaucrat::getGrade() const{
    return this->grade;
}

void Bureaucrat::increment_Grade(){
    this->grade--;
    if(this->grade<1)
        throw GradeTooHighException();
}

void Bureaucrat::decrement_Grade(){
    this->grade++;
    if(this->grade>150)
        throw GradeTooLowException();
}

void Bureaucrat::signForm(AForm &form){
    try
    {
        form.beSigned(*this);
        std::cout<<this->name<<" signed "<<form.getname()<<std::endl;
    }
    catch(std::exception &e)
    {
            std::cout<<this->name<<" couldn't sign "<<form.getname()<<" because "<<e.what()<<std::endl;
    }
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Exception: Grade Too Low!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Exception: Grade Too High!";
}

std::ostream& operator<<(std::ostream &obj, const Bureaucrat &bureaucrat) {
    obj << bureaucrat.getName()<< " , bureaucrat grade " << bureaucrat.getGrade()<<"."<< std::endl;
    return obj;
}
