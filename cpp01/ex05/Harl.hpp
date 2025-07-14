
#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string.h>


class Harl{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

        struct level 
        {
            std::string level;
            void (Harl::*f)();
        };
        level level[4];
    public:
        Harl();
        ~Harl();
        void complain(std::string lev);
};



#endif