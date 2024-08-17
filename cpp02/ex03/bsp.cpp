
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point){

    float S=0;
    float S1=0;
    float S2=0;
    float S3=0;

    S  = (0.5)*(a.get_xpoint()*(b.get_ypoint()-c.get_ypoint())\
    +b.get_xpoint()*(c.get_ypoint()-a.get_ypoint())\
    +c.get_xpoint()*(a.get_ypoint()-b.get_ypoint()));

    S1 = (0.5)*(point.get_xpoint()*(b.get_ypoint()-c.get_ypoint())\
    +b.get_xpoint()*(c.get_ypoint()-point.get_ypoint())\
    +c.get_xpoint()*(point.get_ypoint()-b.get_ypoint()));

    S2 = (0.5)*(a.get_xpoint()*(point.get_ypoint()-c.get_ypoint())\
    +point.get_xpoint()*(c.get_ypoint()-a.get_ypoint())\
    +c.get_xpoint()*(a.get_ypoint()-point.get_ypoint()));

    S3 = (0.5)*(a.get_xpoint()*(b.get_ypoint()-point.get_ypoint())\
    +b.get_xpoint()*(point.get_ypoint()-a.get_ypoint())\
    +point.get_xpoint()*(a.get_ypoint()-b.get_ypoint()));

    // std::cout<<"S= " << S<<std::endl;
    // std::cout<<"S1= " << S1<<std::endl;
    // std::cout<<"S2= " << S2<<std::endl;
    // std::cout<<"S3= " << S3<<std::endl;
    // std::cout<<"Soume= " << S1+S2+S3 <<std::endl;

    if(!S1 || !S2 || !S3 ||(S1+S2+S3) != S)
        return (false);
    else
        return (true);
}