
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point){

    float S=0;
    float S1=0;
    float S2=0;
    float S3=0;

    S  = (0.5)*fabs(((a.get_xpoint().toFloat())*((b.get_ypoint().toFloat())-(c.get_ypoint().toFloat()))\
    +(b.get_xpoint().toFloat())*((c.get_ypoint().toFloat())-(a.get_ypoint().toFloat()))\
    +(c.get_xpoint().toFloat())*((a.get_ypoint().toFloat())-(b.get_ypoint().toFloat()))));

    S1 = (0.5)*fabs(((point.get_xpoint().toFloat())*((b.get_ypoint().toFloat())-(c.get_ypoint().toFloat()))\
    +(b.get_xpoint().toFloat())*((c.get_ypoint().toFloat())-(point.get_ypoint().toFloat()))\
    +(c.get_xpoint().toFloat())*((point.get_ypoint().toFloat())-(b.get_ypoint().toFloat()))));

    S2 = (0.5)*fabs(((a.get_xpoint().toFloat())*((point.get_ypoint().toFloat())-(c.get_ypoint().toFloat()))\
    +(point.get_xpoint().toFloat())*((c.get_ypoint().toFloat())-(a.get_ypoint().toFloat()))\
    +(c.get_xpoint().toFloat())*((a.get_ypoint().toFloat())-(point.get_ypoint().toFloat()))));

    S3 = (0.5)*fabs(((a.get_xpoint().toFloat())*((b.get_ypoint().toFloat())-(point.get_ypoint().toFloat()))\
    +(b.get_xpoint().toFloat())*((point.get_ypoint().toFloat())-(a.get_ypoint().toFloat()))\
    +(point.get_xpoint().toFloat())*((a.get_ypoint().toFloat())-(b.get_ypoint().toFloat()))));

    if(S1>0 && S2>0 && S3>0 &&(S-(S1+S2+S3))==0){
        return (true);}
    else
    { 
        return (false);
    }
}