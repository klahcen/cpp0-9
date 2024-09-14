
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat(std::string name, int grade);
        Bureaucrat& operator= (const Bureaucrat &other);
        std::string getName();
        int getGrade();
        void signForm(Form &form);
        void increment_Grade();
        void decrement_Grade();
        ~Bureaucrat();

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
};
#endif