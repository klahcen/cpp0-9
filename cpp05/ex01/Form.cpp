
#include "Form.hpp"


Form::Form() 
    : name(""),is_signed(false), grade_to_signed(149), graed_to_execute(149){}


Form::Form(std::string name, int grade_s, int grade_e) 
    : name(name), is_signed(false), grade_to_signed(grade_s), graed_to_execute(grade_e)
{
    if(this->grade_to_signed < 1 || this->graed_to_execute < 1)
        throw Form::GradeTooHighException();
    else if(this->grade_to_signed > 150 || this->graed_to_execute > 150)
        throw Form::GradeTooLowException();
}       

Form::Form(const Form &other)
    : name(other.name), is_signed(other.is_signed),
      grade_to_signed(other.grade_to_signed), graed_to_execute(other.graed_to_execute){}

Form& Form::operator= (const Form &other){
    if(this != &other)
        this->is_signed = other.is_signed;
    return *this;
}   
void Form::beSigned(Bureaucrat &bureaucrat){
    if(bureaucrat.getGrade() <= this->grade_to_signed && !this->is_signed)
        this->is_signed = true;
    else if(!this->is_signed)
        throw Form::GradeTooLowException();
    else if(this->is_signed)
        throw Form::IsSignedException();
}

std::string Form::getname() const{
    return this->name;
}

int  Form::getgraed_s()const{
    return this->grade_to_signed;
}
int  Form::getgraed_e()const{
    return this->graed_to_execute;
}
bool Form::getis_signed()const{
    return this->is_signed;
}


Form::~Form(){

}

const char *Form::GradeTooLowException::what() const throw(){
    return "Exception: Grade Too Low!";
}
const char *Form::IsSignedException::what() const throw(){
        return "Exception: Form already Signed!";
}
const char *Form::GradeTooHighException::what() const throw(){
    return "Exception: Grade Too High!";
}

std::ostream& operator<<(std::ostream &obj, const Form &form) {
    obj << "Form Name: " << form.getname() << std::endl
       << "Is Signed: " << (form.getis_signed() ? "Yes" : "No") << std::endl
       << "Grade Required to Sign: " << form.getgraed_s() << std::endl
       << "Grade Required to Execute: " << form.getgraed_e() << std::endl;
    return obj;
}