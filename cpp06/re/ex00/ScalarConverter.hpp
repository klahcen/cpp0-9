#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

class ScalarConverter
{
    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
    public :
        ScalarConverter& operator= (const ScalarConverter &other);
        ~ScalarConverter();
        static void convert(std::string str);
};

#endif

