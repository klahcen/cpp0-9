#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        const std::string name;
        bool   is_signed;
        const int grade_to_signed;
        const int graed_to_execute;
        std::string target;
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(std::string name, int grade_s, int grade_e, std::string target);
        RobotomyRequestForm& operator= (const RobotomyRequestForm &other);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
};

#endif