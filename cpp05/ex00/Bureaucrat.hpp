
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat{
    private:
        const std::string name;
        int grade;
    public:
        std::string getName();
        int getGrade();
        void increment_Grade();
        void decrement_Grade();

        class GradeTooHighException : std::exception
        {
            char *what()
        };

};
#endif