
#include "Phonebook.hpp"


std::string Contact::getFirst_name(){
    return(Contact::first_name);
}
std::string Contact::getNickname_name(){
    return(Contact::nickname_name);
}

std::string Contact::getLast_name(){
    return(Contact::last_name);
}

std::string Contact::getDarkest_secret(){
    return(Contact::darkest_secret);
}

std::string Contact::getPhonr_number(){
    return(Contact::phonr_number);
}



void Contact::setFirst_name(std::string first_name){
    Contact::first_name = first_name;
}

void Contact::setLast_name(std::string last_name){
    Contact::last_name = last_name;
}

void Contact::setNickname_name(std::string nickname_name){
    Contact::nickname_name = nickname_name;
}

void Contact::setDarkest_secret(std::string darkest_secret){
    Contact::darkest_secret = darkest_secret;
}

void Contact::setPhonr_number(std::string phonr_number){
    Contact::phonr_number = phonr_number;
}
