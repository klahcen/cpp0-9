
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool   is_signed;
        const int grade_to_signed;
        const int graed_to_execute;
    public:
        Form();
        Form(std::string name, int grade_s, int grade_e);
        Form(const Form &other);
        Form& operator= (const Form &other);
        void beSigned(Bureaucrat &bureaucrat);
        std::string getname()const;
        int  getgraed_s()const;
        int  getgraed_e()const;
        bool getis_signed()const;
        ~Form();
    
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

};
std::ostream& operator<<(std::ostream &os, const Form &form);
#endif