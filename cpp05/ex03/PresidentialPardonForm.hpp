#ifndef PRESIDENTIALPARADONFORM_HPP
#define PRESIDENTIALPARADONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const std::string name;
        bool   is_signed;
        const int grade_to_signed;
        const int graed_to_execute;
        std::string target;
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm (std::string name, int grade_s, int grade_e, std::string target);
        PresidentialPardonForm(const PresidentialPardonForm  &other);
        PresidentialPardonForm& operator= (const PresidentialPardonForm &other);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const & executor) const;    
};

#endif