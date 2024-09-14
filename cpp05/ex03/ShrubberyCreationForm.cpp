#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm(), target(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm",25, 5), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm &other)
{
    if(this != &other)
    {
        this->target = other.target;
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
    outFile.close();
}