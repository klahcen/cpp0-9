#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string name;
        bool   is_signed;
        const int grade_to_signed;
        const int graed_to_execute;
        std::string target;
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(std::string name, int grade_s, int grade_e, std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm& operator= (const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
};

#endif