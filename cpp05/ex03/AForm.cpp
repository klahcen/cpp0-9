
#include "AForm.hpp"


AForm::AForm() : name(""),is_signed(false), grade_to_signed(149), graed_to_execute(149){}


AForm::AForm(std::string name, int grade_s, int grade_e) : name(name), \
is_signed(false), grade_to_signed(grade_s), graed_to_execute(grade_e)
{
    if(this->grade_to_signed < 1 || this->graed_to_execute < 1)
        throw AForm::GradeTooHighException();
    else if(this->grade_to_signed > 150 || this->graed_to_execute > 150)
        throw AForm::GradeTooLowException();
}       

AForm::AForm(const AForm &other)
    : name(other.name), is_signed(other.is_signed),
      grade_to_signed(other.grade_to_signed), graed_to_execute(other.graed_to_execute){}

AForm& AForm::operator= (const AForm &other){
    if(this != &other)
        this->is_signed = other.is_signed;
    return *this;
} 

void AForm::beSigned(Bureaucrat &bureaucrat){
    if(bureaucrat.getGrade() <= this->grade_to_signed && !this->is_signed)
        this->is_signed = true;
    else if(!this->is_signed)
        throw AForm::GradeTooLowException();
    else if(this->is_signed)
        throw AForm::IsSignedException();
}

std::string AForm::getname() const{
    return this->name;
}

int  AForm::getgraed_s()const{
    return this->grade_to_signed;
}
int  AForm::getgraed_e()const{
    return this->graed_to_execute;
}
bool AForm::getis_signed()const{
    return this->is_signed;
}


AForm::~AForm(){

}

const char *AForm::GradeTooLowException::what() const throw(){
    return "Exception: Grade Too Low!";
}
const char *AForm::IsSignedException::what() const throw(){
        return "Exception: Form already Signed!";
}
const char *AForm::NotSignedException::what() const throw(){
        return "Exception: Form Not Signed!";
}
const char *AForm::GradeTooHighException::what() const throw(){
    return "Exception: Grade Too High!";
}

const char *AForm::Error::what() const throw(){
    return "Exception: Doesn't Exist The Name!";
}

void AForm::check_re(Bureaucrat const & executor) const
{
    if(!(this->is_signed && this->graed_to_execute >= executor.getGrade()))
    {
        if(!this->is_signed)
            throw AForm::NotSignedException();
        throw AForm::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream &obj, const AForm &Aform) {
    obj << "AForm Name: " << Aform.getname() << std::endl
       << "Is Signed: " << (Aform.getis_signed() ? "Yes" : "No") << std::endl
       << "Grade Required to Sign: " << Aform.getgraed_s() << std::endl
       << "Grade Required to Execute: " << Aform.getgraed_e() << std::endl;
    return obj;
}