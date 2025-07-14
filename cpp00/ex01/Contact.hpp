#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string.h>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";

class   Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname_name;
        std::string darkest_secret;
        std::string phonr_number;
    public:
        std::string getFirst_name();
        std::string getLast_name();
        std::string getNickname_name();
        std::string getDarkest_secret();
        std::string getPhonr_number();

        void setFirst_name(std::string first_name);
        void setLast_name(std::string last_name);
        void setNickname_name(std::string nickname_name);
        void setDarkest_secret(std::string darkest_secret);
        void setPhonr_number(std::string phonr_number);
};

#endif