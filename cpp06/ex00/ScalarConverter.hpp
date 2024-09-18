#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

class ScalarConverter
{
    private :
    public :
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        static void convert(std::string str);
        ~ScalarConverter();
        ScalarConverter& operator= (const ScalarConverter &other);
};

#endif

