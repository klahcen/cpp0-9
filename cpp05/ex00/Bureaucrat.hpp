
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat{
    private:
        int grade;
        const std::string name;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat(int grade, std::string name);
        Bureaucrat& operator= (const Bureaucrat &other);
        std::string getName()const;
        int getGrade()const;
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

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
#endif