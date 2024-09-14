
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm{
    private:
        const std::string name;
        bool   is_signed;
        const int grade_to_signed;
        const int graed_to_execute;
    public:
        AForm();
        AForm(std::string name, int grade_s, int grade_e);
        AForm(const AForm &other);
        AForm& operator= (const AForm &other);
        void beSigned(Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const=0;
        std::string getname()const;
        int  getgraed_s()const;
        int  getgraed_e()const;
        bool getis_signed()const;
        void check_re(Bureaucrat const & executor) const;
        virtual ~AForm();
    
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what( void ) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
        class IsSignedException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
        class NotSignedException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
        class Error : public std::exception
        {
            public:
                const char *what(void) const throw();
        };

};
std::ostream& operator<<(std::ostream &os, const AForm &Aform);
#endif