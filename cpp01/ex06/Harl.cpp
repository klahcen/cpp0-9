#include "Harl.hpp"

void Harl::debug(void){
    std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"<<std::endl;
    std::cout<<"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"<<std::endl;
    std::cout <<"I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."<<std::endl;
    std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::info(void){
    std::cout<<"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"<<std::endl;
    std::cout <<"I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."<<std::endl;
    std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::warning(void){
    std::cout <<"I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."<<std::endl;
    std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::error(void){
    std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*f)() = NULL;
    std::string flag[] = {"DEBUG","INFO","WARNING","ERROR"};
    int i;
    for(i=0; i < 4; i++){
        if(flag[i]==level)
            break;
    }
    switch (i)
    {
        case 0:
            f = &Harl::debug;
            break;
        case 1:
            f = &Harl::info;
            break;
        case 2:
            f = &Harl::warning;
            break;
        case 3:
            f = &Harl::error;
            break;
        default :
            std::cout << "Error" << std::endl;
            return ;
    }
    (this->*f)();
}