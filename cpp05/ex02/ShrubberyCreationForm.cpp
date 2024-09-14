#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : name(), is_signed(false), grade_to_signed(145), graed_to_execute(137), target(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int grade_s, int grade_e, std::string target)
    : name(name), is_signed(false), grade_to_signed(grade_s), graed_to_execute(grade_e), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : name(other.name), is_signed(other.is_signed), grade_to_signed(other.grade_to_signed), \
    graed_to_execute(other.graed_to_execute), target(other.target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm &other)
{
    if(this != &other)
    {
        this->is_signed = other.is_signed;
        this->target = other.is_signed;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->check_re(executor);
    std::string outfile = this->target+"_shrubbery";
    std::ofstream outFile;
    outFile.open(outfile.c_str());
    outFile
    <<"      /\\      "<<std::endl
    <<"     /\\*\\     "<<std::endl
    <<"    /\\O\\*\\    "<<std::endl
    <<"   /*/\\/\\/\\   "<<std::endl
    <<"  /\\O\\/\\*\\/\\ "<<std::endl 
    <<" /\\*\\/\\*\\/\\/\\ "<<std::endl
    <<"/\\O\\/\\/*/\\/O/\\ "<<std::endl
    <<"      ||      "<<std::endl
    <<"      ||      "<<std::endl
    <<"      ||"<<std::endl;
}