#include "Harl.hpp"

void Harl::debug(void){
    std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"<<std::endl;
}

void Harl::info(void){
    std::cout<<"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"<<std::endl;
}

void Harl::warning(void){
    std::cout <<"I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."<<std::endl;
}

void Harl::error(void){
    std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

Harl::Harl()
{
    level[0].level = "DEBUG";
    level[0].f =  &Harl::debug;
    level[1].level = "INFO";
    level[1].f =  &Harl::info;
    level[2].level = "WARNING";
    level[2].f =  &Harl::warning;
    level[3].level = "ERROR";
    level[3].f = &Harl::error;
}
Harl::~Harl()
{
    
}

void Harl::complain(std::string lev)
{
   
    for(int i=0; i < 4; i++)
    {
        if(level[i].level == lev)
        {
            (this->*(level[i].f))();
            return ;
        }
    }
    std::cout<<"Error"<<std::endl;
}