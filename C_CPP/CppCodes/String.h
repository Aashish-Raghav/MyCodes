#include<iostream>
#ifndef String_H_
#define String_H_

class String
{
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
    //constructors and other methods;
    String();
    String(const char * s);
    String(const String & st);
    ~String();
    int length() const {return len;}
    void stringlow();
    void stringup();
    int has(char);
    
    //operator overloading;
    String & operator=(const String & st);
    String & operator=(const char * s);
    char & operator[](int i);
    const char & operator[](int i) const;

    //friends
    friend bool operator<(const String & s1,const String & s2);
    friend bool operator>(const String & s1,const String & s2);
    friend bool operator==(const String & s1,const String & s2);
    friend String operator+(const String & s1,const String & s2);
    friend String operator+(const char * s,const String & st);
    friend String operator+(const String & st,const char * s);
    friend std::istream & operator>>(std::istream & is,String & st);
    friend std::ostream & operator<<(std::ostream & os,const String & st);

    //second argument must use reference here because of allocating dynamic memory with new

    //static function;
    static int HowMany();
};

#endif