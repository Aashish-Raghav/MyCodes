#include "complex0.h"

//constructor;
complex::complex()
{
    real_ = img_ = 0;
}

complex::complex(double r,double i)
{
    real_ = r;
    img_ = i;
}


//operator overloading;
complex complex::operator+(const complex & c) const
{
    complex add;
    add.real_ = this->real_ + c.real_;
    add.img_ = this->img_ + c.img_;
    return add;
}

complex complex::operator-(const complex & c) const
{
    complex minus;
    minus.real_ = this->real_ - c.real_;
    minus.img_ = this->img_ - c.img_;
    return minus;
}

complex complex::operator*(const complex & c) const
{
    complex mult;
    mult.real_ = this->real_*c.real_ - this->img_*c.img_;
    mult.img_ = this->real_*c.img_ + this->img_*c.real_;
    return mult;
}

complex complex::operator*(double num) const
{
    return complex(real_*num,img_*num);
}

//friend function;
complex operator~(const complex & c)
{
    return complex(c.real_,-c.img_);
}

complex operator*(double num,const complex & c)
{
    return c * num;
}

std::istream & operator>>(std::istream & input,complex & c) //if didn't use refrence here no is not saved;
{
    std::cout << "Real : ";
    input >> c.real_;
    std::cout << "Imaginary : ";
    input >>c.img_;
    return input;
}

std::ostream & operator<<(std::ostream & os,complex c)      //don't use here refrence otherwise a + c is not a variable to hold refrence;***
{
    os << " (" << c.real_ << "," << c.img_ << "i)";
    return os;
}