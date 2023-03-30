#include<cstring>
#include "String.h"
#include<cctype>
using std::cout;

int String::num_strings = 0; //initialize static member outside class declaration because not constant;

String::String()
{
    str = nullptr;
    num_strings++;
}

String::String(const char * s)
{
    len = strlen(s);
    str = new char[len+1];
    strcpy(str,s);
    num_strings++;
}

String::String(const String & st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    strcpy(str,st.str);
}

String::~String()
{
    --num_strings;
    delete [] str;
}

void String::stringlow()
{
    for (char *ptr = &str[0];ptr < &str[len];ptr++)       //or simply using index like in stringup;
    {
        *ptr = tolower(*ptr);
    }
}

void String::stringup()
{
    for (int i = 0;i < len;i++)
    {
        str[i] = toupper(str[i]);
    }
}

int String::has(char c)
{
    int count = 0;
    for (char *ptr = &str[0];ptr < &str[len -1];ptr++)
    {
        if (*ptr == c) count++;
    }
    return count;
}

String & String::operator=(const String & st)
{
    if (this == &st) return *this;      //self assingment;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str,st.str);
    return *this;
}

String & String::operator=(const char * s)
{
    delete [] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str,s);
    return *this;
}

char & String::operator[](int i)        //read write both;
{
    return str[i];
}

const char & String::operator[](int i) const        //read only;
{
    return str[i];                      
}


bool operator>(const String & s1,const String & s2)      // using friend function;
{
    if (strcmp(s1.str,s2.str) > 0) return true;
    else return false;
}

bool operator<(const String & s1,const String & s2)
{
    if (strcmp(s1.str,s2.str) < 0) return true;     // return s2 > s1;
    else return false;
}

bool operator==(const String & s1,const String & s2)
{
    if (strcmp(s1.str,s2.str) == 0) return true;    //return strcmp(s1.str,s2.str) == 0
    return false;
}

String operator+(const String & s1,const String & s2)
{
    String newobj;
    newobj.len = s1.len + s2.len ;
    newobj.str = new char[newobj.len+ 1];
    strcpy(newobj.str,s1.str);
    strcat(newobj.str,s2.str);
    return newobj;
}

String operator+(const char * s,const String & st)
{
    return String(s) + st;
}

String operator+(const String & st,const char * s)
{
    return st + String(s);
}

std::istream & operator>>(std::istream & input,String & st)
{
    char temp[String::CINLIM];
    input.get(temp,String::CINLIM);
    if (input)
        st = temp;
    while (input && input.get() != '\n') 
        continue;
    return input;
}

std::ostream & operator<<(std::ostream & os,const String & st)
{
    os << st.str;
    return os;
}

int String::HowMany()
{
    return num_strings;
}