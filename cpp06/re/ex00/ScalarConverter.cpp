#include "ScalarConverter.hpp"

int parss_input(std::string str){
    const char *s = str.c_str();
    if(str.size()==1)
    {
        if((static_cast<int>(s[0])>=0 && static_cast<int>(s[0])<128)||std::isalpha(*s) || std::isalnum(*s))
            return 0;
        else
            return 1;
    }
    else
    {
        int r=0;
        int p=0;
        int si=0;
        if(s[str.size()-1] == 'f')
            r++;
        if(s[str.size()-1] == '.' || (s[str.size()-1] == 'f' && s[str.size()-2] == '.'))
            return 1;
        for(unsigned int i=0; i < str.size()-r ;i++)
        {
            if((std::isalpha(s[i]))||(s[i]!='.'&&!(std::isalnum(s[i]))&&((s[i]=='-'||s[i]=='+')&&i>0)))
                return 1;
            if(s[i]=='.')
                p++;
            if(s[i]=='-'||s[i]=='+')
                si++;
            if((s[i+1]&&s[i]=='.'&&!std::isalnum(s[i+1]))||p>1||si>1)
                return 1;
        }
    }
    return 0;
}

void a_char(std::string str){
    const char *s=str.c_str();
    int n = atoi(s);
    if(n==0 && str.find('.')){
         if(*s>=32 && *s<=127)
            std::cout<<"char: \'"<<static_cast<char>(*s)<<"\'"<<std::endl;
        else
            std::cout<<"char: Non displayable."<<std::endl;
    }
    else if((n==-1 && str!="-1")||(n==0 && str!="0"&&str.size()>1)||(n<0 || n>127))
        std::cout<<"char: overflows."<<std::endl;
    else if(n!=0||str == "0")
    {
        if(n>=32 && n<=127)
            std::cout<<"char: \'"<<static_cast<char>(n)<<"\'"<<std::endl;
        else
            std::cout<<"char: Non displayable."<<std::endl;
    }
    else if(str.size()==1)
    {
        if(static_cast<int>(str.c_str()[0])>=32 && static_cast<int>(str.c_str()[0])<=127)
            std::cout<<"char: \'"<<str<<"\'"<<std::endl;
        else
          std::cout<<"char: Non displayable."<<std::endl;
    }
    else
            std::cout<<"char: Non displayable."<<std::endl;
}

void a_int(std::string str){
    const char *s=str.c_str();
    int n = atoi(s);
     if(n==0 && str.find('.'))
        std::cout<<"int: "<<static_cast<int>(*s)<<std::endl;
    else if((n==-1 && str!="-1")||(n==0 && str!="0"&&str.size()>1))
        std::cout<<"int: overflows."<<std::endl;
    else if(n!=0||str == "0")
        std::cout<<"int: "<<n<<std::endl;
    else
        std::cout<<"int: "<<static_cast<int>(*s)<<std::endl;
}

void a_float(std::string str){
    const char *s = str.c_str();
    float f = static_cast<float>(atof(s));
    if(str.size()==1)
    {
        if(*s>57 || *s<48)
            std::cout<<"float: "<<static_cast<float>(*s)<<".0f"<<std::endl;
        else
            std::cout<<"float: "<<static_cast<float>(f)<<".0f"<<std::endl;
    }
    else
    {
        if(str.find('.'))
            std::cout<<"float: "<<static_cast<float>(f)<<"f"<<std::endl;
        else
            std::cout<<"float: "<<static_cast<float>(f)<<".0f"<<std::endl;
    }
}

void a_double(std::string str){
    const char *s = str.c_str();
    double d = static_cast<double>(atof(s));
    if(str.size()==1)
    {
        if(*s>57 || *s<48)
            std::cout<<"double: "<<static_cast<double>(*s)<<".0"<<std::endl;
        else
            std::cout<<"double: "<<static_cast<double>(d)<<".0"<<std::endl;
    }
    else
    {
        if(str.find('.'))
            std::cout<<"double: "<<static_cast<double>(d)<<std::endl;
        else
            std::cout<<"double: "<<static_cast<double>(d)<<".0"<<std::endl;
    }
}

void ScalarConverter::convert(std::string str)
{
    std::string s[8]={"nan","inf","+inf","-inf","nanf","inff","+inff", "-inff"};
    int i=-1;
    for(i=0 ; i < 9; ++i)
    {
        if(str == s[i])
            break;
    }
    if(i<9&&i>=0)
    {
        std::cout<<"char: overflows."<<std::endl;
        std::cout<<"int: overflows."<<std::endl;
        if(i < 4){
            std::cout<<"float: "<<str<<"f"<<std::endl;
            std::cout<<"double: "<<str<<std::endl;
        }
        else{
            std::cout<<"float: "<<s[i-4]<<"f"<<std::endl;
            std::cout<<"double: "<<s[i-4]<<std::endl;
        }
    }
    else
    {
        int v = parss_input(str);
        if(v==0){
            a_char(str);
            a_int(str);
            a_float(str);
            a_double(str);
        }
        else
            std::cout<<"bad input"<<std::endl;
    }
}

ScalarConverter::ScalarConverter(){

}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
    *this = other;
}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter &other){
    if(this != &other){}
    return *this;
}

ScalarConverter::~ScalarConverter(){

}