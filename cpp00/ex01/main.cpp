
#include "Phonebook.hpp"

void    Phonebook::Add(int nbr){
    std::string str;
    std::cout<<YELLOW<<"first name : "<<RESET;
    std::getline(std::cin, str);
    contact[nbr].setFirst_name(str);
    std::cout<<YELLOW<<"last name : "<<RESET;
    std::getline(std::cin, str);
    contact[nbr].setLast_name(str);
    std::cout<<YELLOW<<"nick name : "<<RESET;
    std::getline(std::cin, str);
    contact[nbr].setNickname_name(str);
    std::cout<<YELLOW<<"phone name : "<<RESET;
    std::getline(std::cin, str);
    contact[nbr].setPhonr_number(str);
    std::cout<<YELLOW<<"darkest name : "<<RESET;
    std::getline(std::cin, str);
    contact[nbr].setDarkest_secret(str);
}
void    Phonebook::Search(int nbr){

    std::string str;
    int         digit=0;

    if(nbr==0)
        std::cout<<BLUE<<"Wrong optins!!"<<std::endl<<RESET;
    else
    {
        for(int i=0; i < nbr; i++)
        {
            if(i > 7)
                break;
            std::cout<<RED<<"\t"<<i<<"|\t"<<contact[i].getFirst_name()<<"|\t";
            std::cout<<contact[i].getLast_name()<<"|\t";
            std::cout<<contact[i].getNickname_name()<<RESET<<std::endl;
        }
        std::cout<<BLUE<<"Enter index of contact to show their more informations : "<<RESET;
        std::getline(std::cin, str);
        digit = stoi(str);
        if(digit>nbr || digit > 7)
            std::cout<<BLUE<<"Your input out of range!!"<<std::endl<<RESET;
        else if(digit<nbr && digit <= 7 && digit >= 0)
        {
            std::cout<<BLUE<<"==> first name   : "<<contact[digit].getFirst_name()<<std::endl;
            std::cout<<"==> last name    : "<<contact[digit].getLast_name()<<std::endl;
            std::cout<<"==> nick name    : "<<contact[digit].getNickname_name()<<std::endl;
            std::cout<<"==> phone name   : "<<contact[digit].getPhonr_number()<<std::endl;
            std::cout<<"==> darkest name : "<<contact[digit].getDarkest_secret()<<std::endl<<RESET;
        }
    }
}


int main()
{
    Phonebook phonebook;
    char      chois[1024];
    static int i=0;
    phonebook.nbr = 0;
    while (1)
    {
        std::cout<<GREEN<<"************Your options: ADD,  SEARCH, EXIT************"<<std::endl;
        std::cout<<"Please Enter you option : ";
        std::cin.getline(chois, 1024);
        std::cout<<RESET;
        if(!strcmp(chois, "ADD"))
        {
            phonebook.Add(i++);
            phonebook.nbr++;
        }
        if(!strcmp(chois, "SEARCH"))
            phonebook.Search(phonebook.nbr);
        if(!strcmp(chois, "EXIT"))
            exit(1);
        if(i > 7)
            i = 0;
    }
}