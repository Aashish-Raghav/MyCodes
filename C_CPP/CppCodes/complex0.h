#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include<iostream>

class complex
{
private:
    int real_;
    int img_;
public:
    complex(double r,double i);
    complex();

    //operator overloading;
    complex operator+(const complex & c) const;
    complex operator-(const complex & c) const;
    complex operator*(const complex & c) const;
    complex operator*(double num) const;

    //friend fxn;
    friend complex operator~(const complex & c);
    friend complex operator*(double num,const complex & c);
    friend std::istream & operator>>(std::istream & input,complex & c);
    friend std::ostream & operator<<(std::ostream & os,complex c);
    
    
};

#endif